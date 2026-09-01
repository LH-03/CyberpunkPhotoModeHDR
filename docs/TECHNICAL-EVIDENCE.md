# Technical evidence and differentiation

This page documents what a user or reviewer can observe in v0.1 and how those
observations distinguish the mod from a display screenshot or tone-mapping mod.
It deliberately does not contain enough private implementation detail to
rebuild the shipping hook and capture path.

## Observable integration evidence

1. A capture ticket is created only when Cyberpunk's semantic Photo Mode action
   `TakeScreenshot_HiRes` is received. The original handler still runs.
2. Cyberpunk's own blackout, save notification, and native PNG occur normally.
3. The ticket does not advance merely because time elapsed. Diagnostics record
   the same-shot native PNG becoming exclusively openable with a complete
   `IEND`, followed by acceptance of the next qualified internal frame.
4. The accepted image is a current-resolution, UI-free RGBA16F Photo Mode
   resource with public audit label `A852 -> 341`; it is not the desktop or
   final swap chain.
5. Runtime HDR10 PQ paper white and peak values are captured for that shot and
   passed with CPU-owned staging pixels to the Ultra HDR worker.
6. The result is an Ultra HDR JPEG with an SDR fallback and gain map. The
   game's original PNG remains available unless the optional Gallery proxy is
   explicitly enabled.

A sanitized diagnostic sequence looks like this:

```text
native Photo Mode shutter: ticket armed; original action forwarded
native PNG ready: file closed and complete IEND observed
internal Photo Mode FP16 gate: exact branch accepted for ticket
GPU readback complete: CPU staging queued
worker complete: Ultra HDR output written
```

## How this differs from other HDR-related approaches

There are several legitimate but different categories of tools:

- **Display/tone-map mods** change how the live game is presented. They may
  improve gameplay HDR but do not by themselves repair Photo Mode file output.
- **Overlay, driver, desktop, or swap-chain capture tools** save the final
  presented image. They can produce excellent HDR screenshots but operate
  outside Cyberpunk's native Photo Mode file path.
- **CyberpunkPhotoModeHDR** observes the game's native shutter, preserves its
  photo task, and reads an internal UI-free FP16 Photo Mode branch before CPU
  Ultra HDR encoding.

This is an architectural distinction, not a claim that every other HDR mod
uses the same method or produces inferior images.

## v0.1 validation record

Validated on one system only:

- Cyberpunk 2077 Steam 2.31;
- RTX 5070 Laptop GPU, 8 GB VRAM;
- 2560x1600 final acceptance capture, plus basic successful checks at other
  game resolutions on the same system;
- HDR10 PQ;
- basic successful output checks with ray tracing disabled and at multiple RT
  quality levels on the same system;
- owner-observed comparison on the game display, a PC viewer, and a phone with
  Ultra HDR gain-map display support.

The owner accepted the final `Faithful` result and the optional `Rich` result.
The temporal PNG-completion gate was also verified over consecutive captures
after an earlier double-exposure failure was reproduced and isolated.

This is evidence from one system, not a compatibility guarantee for other game
builds, GPUs, path-tracing combinations, displays, or viewers.

## Evidence boundary

The public repository gives reviewers a falsifiable control-flow contract and
observable runtime sequence. It intentionally withholds the exact executable
and D3D12 identities that would turn the evidence into a commercial-quality
reproduction recipe. The released binary remains the reference implementation.
