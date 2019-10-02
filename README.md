# `nss_hosthack`: Minimal Skeleton nss host module

* Minimal GNU libc Name Service Switch (nss) host name resolution plugin that just sleeps and return "unavailable"
* Written to help software testing in the face of slow or unreliable DNS service
* Can be used as a skeleton for customizing Linux hostname resolution behavior

# Build
```
$ make
```

# Install
1. Copy `libnss_hosthack.so.2` to `/usr/lib64` (Red Hat) , `/lib/x86_64-linux-gnu/` (Debian), or `/usr/glibc-compat/lib` (alpine-glibc)
2. Copy [`nsswitch.conf`](nsswitch.conf) `/etc/nsswitch.conf`
