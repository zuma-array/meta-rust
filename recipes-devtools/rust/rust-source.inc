require rust-config.inc

RUST_VERSION ?= "${@d.getVar('PV').split('-')[0]}"

SRC_URI += "${RUST_DIST_SERVER}/dist/rustc-${RUST_VERSION}-src.tar.xz;name=rust \
            file://hardcodepaths.patch;patchdir=${RUSTSRC} \
            file://zlib-off64_t.patch;patchdir=${RUSTSRC} \
            file://0001-Revert-Map-source-absolute-paths-to-OUT_DIR-as-relat.patch;patchdir=${RUSTSRC} \
            file://cargo-path.patch;patchdir=${RUSTSRC} \
            file://0001-Handle-vendored-sources-when-remapping-paths.patch;patchdir=${RUSTSRC} \
"
SRC_URI[rust.sha256sum] = "805482b436442a6786d270cacbab8f00529e06141b27b7fb01909b97ce4f3464"

RUSTSRC = "${WORKDIR}/rustc-${RUST_VERSION}-src"

UPSTREAM_CHECK_URI = "https://forge.rust-lang.org/infra/other-installation-methods.html"
UPSTREAM_CHECK_REGEX = "rustc-(?P<pver>\d+(\.\d+)+)-src"
