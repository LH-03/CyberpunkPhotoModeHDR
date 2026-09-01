# Changelog

## v0.1 - Experimental first release

- Hooks Cyberpunk 2077 2.31's native Photo Mode shutter without consuming it.
- Reads the current-resolution FP16 Photo Mode A852-to-341 branch.
- Outputs Ultra HDR JPEG with an SDR fallback and HDR gain map.
- Adds `Faithful`, `Rich`, and single-shutter `Both` output modes.
- Reads runtime HDR10 PQ paper white and peak values from the active render path.
- Waits for the native PNG to close with a complete IEND before accepting the
  next Gate7 frame, avoiding a reproduced temporal-history double-exposure bug.
- Adds an optional, recoverable Gallery SDR proxy; disabled by default in the
  public beta because stickers and frames are not yet carried into HDR/proxy output.
- Tested on one machine and one game build only, including basic successful
  checks across multiple resolutions and several raster/RT settings; see the
  README disclaimer.
