load("//tools:spiral_git.bzl", "spiral_git_repository")

spiral_git_repository(
    name = "boringssl",
    commit = "refs/remotes/origin/spiral-boringssl",
    remote = "git@bitbucket.org:sgteam/boringssl.git",
)

bind(
    name = "openssl",
    actual = "@boringssl//:ssl",
)

new_http_archive(
    name = "openssl_1_0_2k",
    build_file = "openssl.BUILD",
    sha256 = "6b3977c61f2aedf0f96367dcfb5c6e578cf37e7b8d913b4ecb6643c3cb88d8c0",
    url = "https://www.openssl.org/source/openssl-1.0.2k.tar.gz",
)
