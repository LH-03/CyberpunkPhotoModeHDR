# Why Ultra HDR JPEG? / 为什么选择 Ultra HDR JPEG

This project is about Cyberpunk 2077's **native Photo Mode file output**, not
about declaring one image format universally best. Different formats optimize
for different jobs. v0.1 chooses Ultra HDR JPEG because its failure mode is
particularly practical for sharing: an HDR-aware viewer applies the gain map,
while an older JPEG viewer can still open the same file and display its embedded
SDR base image.

本项目解决的是《Cyberpunk 2077》**原生拍照模式的文件输出**，并不是宣称某种
格式在所有用途下都最好。v0.1 选择 Ultra HDR JPEG，主要因为它适合分享：支持
HDR gain map 的设备显示 HDR；不认识 gain map 的普通 JPEG 软件仍可直接打开
同一个文件，并看到内嵌的 SDR 底图。

## Practical comparison / 实用对比

| Route or format | Strengths | Trade-offs | Best fit |
| --- | --- | --- | --- |
| **Ultra HDR JPEG (this mod)** | One `.jpg`; ordinary JPEG fallback; compatible viewers apply an HDR gain map; convenient phone/PC sharing | JPEG base and gain map are lossy; HDR appearance still depends on display boost and viewer tone mapping; some sites/editors may strip the gain map; not a scene-linear master | A photo that should open almost everywhere and gain HDR where supported |
| **NVIDIA HDR screenshot / JXR** | Direct HDR screen capture; JPEG XR supports high dynamic range and can preserve high precision | NVIDIA's own guidance points users to a dedicated Windows HDR viewer; default mobile/gallery support is much less universal than JPEG; captures presented screen output rather than Cyberpunk's native Photo Mode file path | Accurate PC display-output capture in a Windows/NVIDIA workflow |
| **Steam HDR screenshot / AVIF** | Modern HDR-capable container; high compression efficiency and high-bit-depth capability; Steam can save HDR screenshots as AVIF | Viewer and color-management behavior still varies; the reference machine observed a red cast in one viewer, which is a compatibility symptom rather than proof that AVIF itself is wrong; also captures Steam's screenshot path, not the game's native Photo Mode output | Steam-centered HDR screenshots when the target apps handle AVIF correctly |
| **Cyberpunk native PNG** | Lossless SDR pixels; universally easy to inspect; remains the game's Gallery/original-file reference | Cyberpunk's current Photo Mode PNG path does not preserve the HDR highlight range being targeted here, so HDR gameplay can become a flat/washed-out SDR file | Original game compatibility, Gallery, stickers/frames, and an SDR reference |
| **OpenEXR / floating-point master** | High precision, wide range, excellent for compositing, grading, and technical analysis | Very large; inconvenient for phones, galleries, social sites, and casual sharing; usually needs specialist software and an explicit display transform | Production master or post-processing intermediate, not a daily share file |
| **Desktop/driver/overlay screenshot** | Often simple, fast, and close to the final monitor presentation; excellent when that is the desired truth | Includes the presentation path and may include overlays/cursor/UI; does not use Cyberpunk's native Photo Mode render/save lifecycle | Capturing exactly what was presented on screen |

## What “compatible” means here / 这里的“兼容”到底指什么

Ultra HDR does **not** guarantee identical appearance everywhere. It provides a
graceful compatibility ladder:

1. a gain-map-aware HDR viewer can render the adapted HDR rendition;
2. an unaware JPEG viewer can display the SDR base instead of failing to open;
3. a service that recompresses the file may keep only the SDR base and discard
   the gain map.

因此“手机和电脑都能直接打开”并不等于“所有软件都会显示同一份 HDR”。它表示
最差通常还能按普通 JPEG 显示正常 SDR，而不是完全打不开、要求额外安装查看器，
或把未知 HDR 数据用错误色彩解释。完整 HDR 增益仍要求设备、系统和查看软件共同
支持；不同设备的峰值、纸白、显示增益与 tone mapping 也会改变最终观感。

## Why this mod does not replace NVIDIA or Steam capture

NVIDIA JXR and Steam AVIF are useful when the goal is to capture the final
presented screen through their own screenshot paths. CyberpunkPhotoModeHDR is
for a different goal: press Cyberpunk's own Photo Mode shutter, retain the
game's native task and PNG, then repair the missing HDR-capable share output
from an internal UI-free Photo Mode FP16 branch.

Choose by intent:

- **want the monitor output:** use a driver/Steam/desktop HDR screenshot;
- **want an editable high-precision master:** use EXR where available;
- **want Cyberpunk's native Photo Mode plus easy multi-device sharing:** this
  mod's Ultra HDR JPEG is the intended compromise.

The two v0.1 presets are still not strict pixel-for-pixel monitor reproductions,
and Ultra HDR is not lossless archival storage. Those limitations are explicit,
not hidden behind the `.jpg` compatibility advantage.

## Primary references / 一手资料

- [Android Ultra HDR format specification](https://developer.android.com/media/platform/hdr-image-format)
- [Android Ultra HDR support overview](https://developer.android.com/media/grow/ultra-hdr)
- [NVIDIA HDR screenshot/JXR announcement](https://www.nvidia.com/en-us/geforce/news/gfecnt/20216/rtx-on-doom-eternal-game-ready-driver/)
- [Steam Client Update: HDR screenshots as AVIF](https://store.steampowered.com/news/posts/?enddate=1709064894&feed=steam_community_announcements)
- [Microsoft Advanced Color guidance](https://learn.microsoft.com/en-us/windows/win32/direct3darticles/high-dynamic-range)
