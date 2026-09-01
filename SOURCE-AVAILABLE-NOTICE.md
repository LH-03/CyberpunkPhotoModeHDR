# Source-available notice / 有限源码说明

Copyright (c) 2026 CyberpunkPhotoModeHDR Project contributors.

## 中文

CyberpunkPhotoModeHDR v0.1 是一个 **source-available（源码可审阅）** 项目，
不是 OSI 定义下的开源软件。除下方列出的第三方材料外，本项目公开仓库和
二进制发布包中的原创材料按 `PolyForm Noncommercial License 1.0.0` 提供；
完整条款见 `LICENSE.md`。任何超出该许可证允许目的的使用，都需要项目权利人
另行给予书面许可。

公开仓库刻意只提供有限源码和审计材料。它足以说明发布版接入了
《Cyberpunk 2077》的原生拍照快门、原生 PNG 完成时序以及内部无 UI FP16
拍照分支，但 **不是完整、可独立复现的构建源码**。以下未公开材料不属于本次
分发，也没有因本次发布而获得任何许可：

- 精确可执行文件地址、签名和版本适配数据；
- 完整 D3D12 资源/描述符/调用点识别方法；
- 着色器、资源图谱、捕获样本、逆向笔记与自动化工具；
- 生产插件、读回器、色彩变换和编码器的完整实现；
- 私有测试素材、崩溃记录和开发环境信息。

公开的接口契约和删减代码片段用于审计产品边界，不承诺能单独编译出发布版。
不要把“源码可见”误写成“开源”。

## English

CyberpunkPhotoModeHDR v0.1 is **source-available**, not Open Source under the
OSI definition. Except for separately identified third-party materials, the
original works in the public repository and binary package are offered under
the PolyForm Noncommercial License 1.0.0 in `LICENSE.md`. Any use outside a
purpose permitted by that license requires separate written permission from
the relevant rightsholder.

The repository intentionally publishes a limited audit surface. It documents
and demonstrates integration with Cyberpunk 2077's native Photo Mode shutter,
native-PNG completion timing, and an internal UI-free FP16 Photo Mode branch,
but it is **not complete independently reproducible build source**. Exact
addresses and signatures, complete D3D12 resource discovery, shader and graph
artifacts, private captures, production hook/readback/color/encoder source,
and reverse-engineering tooling are withheld and are not licensed by their
absence.

The public contracts and sanitized excerpts exist to make the product boundary
auditable. Source-visible does not mean Open Source.

## Third-party and game rights

libultrahdr, libjpeg-turbo, and the RED4ext SDK remain under their own licenses;
see `THIRD-PARTY-NOTICES.txt` and `licenses/`. Those third-party terms take
priority for their respective materials.

Cyberpunk 2077 and related names and assets belong to their respective owners.
This is an unofficial fan project and is not affiliated with or endorsed by
CD PROJEKT RED. No game assets are distributed by this project.
