# Public architecture / 公开架构

This document describes the shipping boundary without publishing the private
game-version adapter or the complete capture implementation.

```text
Cyberpunk native Photo Mode shutter (TakeScreenshot_HiRes)
                         |
                         v
           forward original game photo task
          (blackout + notification + native PNG)
                         |
                         v
      same-shot PNG closed + complete IEND gate
                         |
                         v
 exact internal UI-free current-resolution FP16 Photo Mode branch
                         |
                         v
 asynchronous GPU readback -> CPU-owned staging memory
                         |
                         v
 runtime PQ paper white/peak + Faithful/Rich transform
                         |
                         v
 Ultra HDR JPEG (SDR base + HDR gain map)
                         |
                         +--> optional recoverable Gallery SDR proxy
```

## What is native here

“Native Photo Mode” means the capture is armed by Cyberpunk 2077's own Photo
Mode shutter and is synchronized with the game's own photo task. The plugin
does not synthesize a separate hotkey, capture the Windows desktop, or read the
final presentation swap chain. The original game's PNG is still produced.

The internal capture point is identified publicly by the stable audit label
`A852 -> 341`. That label is sufficient to correlate public diagnostics and
the source excerpts. Exact executable addresses, signatures, call sites,
descriptor identities, shader/resource graph evidence, and the discovery
method are deliberately excluded.

## Why the PNG completion gate exists

Testing reproduced a temporal-history transition frame immediately after the
shutter. A fixed sleep was not reliable: render modes and machines complete at
different times. v0.1 therefore waits for the same-shot native PNG to be
closed and to contain a complete `IEND`, then accepts the next exact internal
Photo Mode frame. This keeps timing tied to the game's photo task rather than
to one machine's speed.

## HDR output model

The worker receives the current shot's FP16 pixels and runtime HDR10 PQ paper
white/peak values. It produces an Ultra HDR JPEG containing both a broadly
compatible SDR base image and an HDR gain map. `Faithful` and `Rich` are output
presets, not claims of pixel-exact monitor reproduction.

Only HDR10 PQ was validated for v0.1. Unsupported or unrecognized HDR modes
fail closed instead of being silently treated as PQ.

## Public/private boundary

Published:

- state and eligibility contracts;
- sanitized native-shutter integration excerpt;
- end-to-end architecture and observable diagnostics;
- output/configuration behavior and a single-device validation record.

Withheld:

- complete production plugin and worker source;
- exact game-version addresses, signatures, prologues, and fingerprints;
- D3D12 resource/descriptor/call-site discovery and validation;
- shader dumps, graph captures, raw frame samples, and reverse-engineering tools;
- private tests, crash artifacts, and development notes.
