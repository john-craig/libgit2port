# libgit2 for z/OS

libgit2 is a portable, pure C implementation of the Git core methods.
Nix uses libgit2 directly in `libfetchers` to clone and fetch git repositories.

## Installation

```bash
zopen install libgit2
```

## Building from Source

```bash
git clone https://github.com/zopencommunity/libgit2port.git
cd libgit2port
zopen build -vv
```

## Version

Tracks upstream [libgit2/libgit2](https://github.com/libgit2/libgit2).
Nix 2.35.0 requires libgit2 ≥ 1.9.0.

## Dependencies

| Dependency | Source | Notes |
|-----------|--------|-------|
| openssl | zopencommunity | TLS/HTTPS backend |
| libssh2 | zopencommunity | SSH transport |
| zlib | zopencommunity | Compression |
| libpcre2 | zopencommunity | Regex (path matching) |
| pkgconfig | zopencommunity | Build-time detection |

## z/OS Notes

- SSH transport: `libssh2` (available in zopen)
- HTTPS transport: `OpenSSL` backend (available in zopen)
- Regex: `pcre2` backend (available in zopen as `libpcre2`)
- Tests disabled at build time (`BUILD_TESTS=OFF`) for faster initial port
  verification; re-enable with `-DBUILD_TESTS=ON` once the library builds.

## License

GPL-2.0 with linking exception (see [COPYING](https://github.com/libgit2/libgit2/blob/main/COPYING))
