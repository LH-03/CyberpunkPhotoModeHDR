# Cyberpunk 2077 Native Photo Mode Ultra HDR v0.1

An experimental HDR mod integrated with Cyberpunk 2077's native Photo Mode.
You still press the game's own shutter. The mod does not capture the desktop or
presentation swap chain and does not require Steam/NVIDIA/ReShade screenshots.
After the native photo task completes, it reads a current-resolution FP16 image
from an internal UI-free Photo Mode branch and produces an Ultra HDR JPEG with
an SDR fallback and HDR gain map.

## How it differs

- Live HDR/tone-map mods change the gameplay image sent to the display.
- Driver, overlay, desktop, and swap-chain tools save the final presented image.
- This mod observes Cyberpunk's `TakeScreenshot_HiRes` action, preserves the
  native blackout/notification/PNG, and repairs the native Photo Mode file path.

That is an architectural distinction, not a claim that every other HDR mod uses
the same technique or that external HDR capture tools are inferior.

## Read before installing

- v0.1 has been validated on one machine only: Steam 2.31, RTX 5070 Laptop
  8 GB and HDR10 PQ. Basic tests on that machine at multiple resolutions, with
  ray tracing disabled, and at several RT quality levels all produced normal
  output. Other hardware, drivers, mods, path-tracing combinations, and game
  versions may still fail or contain unknown bugs. No compatibility guarantee.
- Neither preset is a strict reproduction of monitor output. `Faithful` was the
  closer reference result on the tested PC and phone. `Rich` is deliberately
  brighter, warmer, and more saturated.
- Paper white, peak brightness, Windows HDR configuration, display capability,
  viewer tone mapping, and gain-map support can change how the same photo looks.
- Only HDR10 PQ is validated. scRGB is not claimed in v0.1.
- Stickers and frames are composited after the current capture point and are not
  present in the Ultra HDR output. Gallery replacement defaults to off.

## Features

- native shutter trigger with the original PNG and notification preserved;
- current-resolution FP16 readback (2560x1600 on the validation system);
- Faithful, Rich, or both from one GPU readback;
- per-shot runtime paper-white and peak values;
- Ultra HDR JPEG with ordinary-JPEG SDR compatibility;
- adaptive native-PNG completion gate to avoid temporal DLSS/TAA/RR/PT frames;
- optional recoverable Gallery SDR proxy.

## Requirements and install

RED4ext is the only runtime prerequisite. Extract the archive into the game
directory. See `README.en.md` for configuration, output, uninstall, and logs.

## Why Ultra HDR JPEG

The goal is practical sharing, not claiming JPEG is universally superior. A
gain-map-aware phone or viewer displays HDR, while an unaware viewer still opens
the same file as an ordinary SDR JPEG. NVIDIA JXR is strong for Windows HDR
screen capture but its own guidance recommends a dedicated Windows HDR viewer;
mobile support is less universal. Steam AVIF is modern and HDR-capable, but
viewer/color-management behavior varies (the reference PC saw a red cast in one
viewer, which is not evidence that AVIF itself is inherently wrong). EXR is a
better high-precision editing master but inconvenient for casual sharing, while
Cyberpunk's PNG remains useful for SDR, Gallery, and decorations. Ultra HDR is
lossy, sites can strip its gain map, and display/viewer differences remain. See
`FORMAT-CHOICE.md` in the archive for the full neutral comparison.

## License and scope

PolyForm Noncommercial 1.0.0; source-available limited source, not MIT and not
OSI Open Source. The GitHub repository publishes audit contracts, sanitized
excerpts, and technical evidence of native Photo Mode integration, while the
complete game adapter, D3D12 discovery, color/encoder implementation, and
reverse-engineering toolchain remain private.

Near-term work may improve device/render-mode coverage, stickers/frames,
Gallery robustness, diagnostics, and avoidable latency. These are investigation
targets, not promises or dates.

If this project is useful, optional support is available through
[Ko-fi (global)](https://ko-fi.com/nofjmt) or
[Afdian (for users in China)](https://afdian.com/a/nofjmt). Donations do not
affect downloads, features, or bug-report handling.
