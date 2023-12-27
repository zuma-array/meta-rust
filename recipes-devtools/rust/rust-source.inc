require rust-config.inc

RUST_VERSION ?= "${@d.getVar('PV').split('-')[0]}"

SRC_URI += "${RUST_DIST_SERVER}/dist/rustc-${RUST_VERSION}-src.tar.xz;name=rust \
            file://hardcodepaths.patch;patchdir=${RUSTSRC} \
            file://zlib-off64_t.patch;patchdir=${RUSTSRC} \
            file://0001-Revert-Map-source-absolute-paths-to-OUT_DIR-as-relat.patch;patchdir=${RUSTSRC} \
            file://0001-Handle-non-existent-empty-CARGO_HOME-registry-src.patch;patchdir=${RUSTSRC} \
            file://0002-Ignore-blank-RUSTC_DEBUGINFO_MAP-RUSTC_CARGO_REGISTR.patch;patchdir=${RUSTSRC} \
"
SRC_URI[rust.sha256sum] = "4526f786d673e4859ff2afa0bab2ba13c918b796519a25c1acce06dba9542340"

RUSTSRC = "${WORKDIR}/rustc-${RUST_VERSION}-src"

UPSTREAM_CHECK_URI = "https://forge.rust-lang.org/infra/other-installation-methods.html"
UPSTREAM_CHECK_REGEX = "rustc-(?P<pver>\d+(\.\d+)+)-src"
