#!/usr/bin/perl -w

use strict;

my %needed_packages = (
    "Net" => 1,
    "NetSSL_OpenSSL" => 1,
    "XML" => 1,
    "Util" => 1,
    "JSON" => 1,
    "Foundation" => 1,
    "Crypto" => 1
    );


my %deps = (
    "XML" => ["//Foundation"],
    "Net" => ["//Foundation", "//Util"],
    "Util" => ["//Foundation", "//XML", "//JSON"],
    "NetSSL" => ["//Net", "//Crypto"],
    "JSON" => ["//Foundation"],
    "Crypto" => ["//Foundation"],
);

my %moreflags = (
    "XML" => '"-DXML_NS","-DXML_DTD","-DHAVE_EXPAT_CONFIG_H",'
    );

for my $mnp (<*/make-n-p>) {
    $mnp =~ /^(.*)\/make-n-p/ || die "could not parse mnp $mnp";
    my $dir = $1;

    next unless $needed_packages{$dir};

    print "Reading $mnp\n";
    open(IN, $mnp) || die "$mnp: $!";
    open(BUILD, ">$dir/BUILD");
    my %seen;
    while (<IN>) {
	chop;
#	         dor/poco/lib/Linux/x86_64/libPocoZip.a: /home/nils/v
	if (m@^/[^ ]+poco/lib/Linux/x86_64/libPoco([a-zA-Z]+)\.a: (.*)$@) {
	    my $libname = $1;
	    my $files = $2;

	    next unless /release_static/;
	    next if $seen{$libname};
	    $seen{$libname}++;
	    print "Found lib $libname with files:\n";
	    printf BUILD ('

cc_library(name="%s",
           hdrs=glob(["include/**/*.h"]),
           includes=["include"],
           visibility = ["//visibility:public"],
           copts=["-Wno-sign-compare", "-Wno-unknown-pragmas",
"-D_XOPEN_SOURCE=500",
"-D_REENTRANT",
"-D_THREAD_SAFE",
"-D_FILE_OFFSET_BITS=64",
"-D_LARGEFILE64_SOURCE",
"-DPOCO_HAVE_FD_EPOLL",
%s
],
           srcs=glob(["src/*.h", "src/*.inc"]) +  [', $libname,
		$moreflags{$dir} || "");
	    for my $file (split(/ +/, $files)) {
		$file =~ s@^.*release_static/@@;
		$file =~ s/\.o$//;
		for my $ext (".cpp", ".c", ".cc") {
		    if ( -f "$dir/src/$file$ext" ) {
			print BUILD "\"src/$file$ext\",";
			print " $file$ext";
		    }
		}
	    }
	    print BUILD "],";
	    if ($deps{$libname}) {
		print BUILD "  deps=[";
		for my $dep (@{$deps{$libname}}) {
		    print BUILD "\"$dep\",";
		}
		print BUILD "],";
	    }
	    print BUILD ")\n";
	    print "\n";
	}
    }
    close(IN);
    close(BUILD);
}
