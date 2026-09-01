# Cyberpunk 2077 原生拍照模式 Ultra HDR v0.1

> 实验性首发版。请先阅读“兼容性与显示差异”。

简体中文 | [English](README.md) | [Nexus Mods](https://www.nexusmods.com/cyberpunk2077/mods/33388)

## v0.1 最终实机验收样张

[![忠实预设最终验收车景](public-media/v0.1-faithful-final-validation.UltraHDR.jpg)](public-media/v0.1-faithful-final-validation.UltraHDR.jpg)

这是精确 v0.1 玩家实机验收第二次快门生成的 2560x1600 原始 Ultra HDR JPEG。
点击图片可下载原文件。

## 用户验收预设对照

| 忠实 | 浓郁 |
| --- | --- |
| ![忠实预设车景](public-media/v0.1-faithful-car.UltraHDR.jpg) | ![浓郁预设车景](public-media/v0.1-rich-car.UltraHDR.jpg) |

两张来自同一次原生拍照快门，均保留为可下载的 2560x1600 原始 Ultra HDR
JPEG。GitHub 或不支持 Ultra HDR 的查看器可能只显示内嵌的 SDR fallback。

## 它和普通截图工具有什么不同

本 MOD 不是 Steam、NVIDIA App、Xbox Game Bar 或桌面截屏，也不从交换链
截取屏幕上已经显示的画面。它监听《Cyberpunk 2077》自己的原生拍照按钮，
保留游戏原有的拍照黑屏、保存通知和 PNG 流程，同时直接从游戏 Photo Mode
内部 `A852 -> 341` 的 FP16 成片支路读取当前游戏分辨率的无控制 UI 图像，
再由 CPU 编码为 Ultra HDR JPEG。

正式运行只需要 RED4ext；不依赖 ReShade、Codeware、REDscript 或外部截图工具。
它也不是实时画面 HDR/色调映射 MOD：它不负责改变游玩时显示器上的画面，
而是修复原生拍照按钮之后的文件输出链路。两类 MOD 可以各自存在。

## 兼容性与显示差异——请先看清楚

- v0.1 目前只在一台设备上完成实机验证：Steam 游戏 2.31、RTX 5070
  Laptop 8GB、HDR10 PQ。在这台设备上又简单测试了多种游戏分辨率，以及关闭
  光追和不同光追档位，均能正常拍照输出；这仍不代表其他显卡、驱动、Windows
  版本、其他 MOD、路径追踪组合或后续游戏版本一定兼容，也可能存在尚未发现的
  Bug；本版本不作保证。
- `忠实` 和 `浓郁` 都不是逐像素复刻显示器上的最终画面。`忠实` 只表示在
  上述参考设备的手机、电脑和游戏实景对比中更接近原画面；`浓郁` 是更亮、
  更饱和、偏暖的风格化预设。
- 同一张 Ultra HDR 照片会受到游戏纸白、峰值亮度、显示器/手机能力、
  Windows HDR 设置、查看器 tone mapping、是否支持 gain map 等因素影响。
  不同设备和软件看到的亮度、颜色、黑位与高光增益出现差异是预期现象。
- 仅验证 HDR10 PQ。scRGB、HDR10+ 动态元数据及未知 HDR 输出模式当前不宣称支持。
- 用户选择的贴纸和相框位于当前 HDR 捕获点之后，v0.1 的 Ultra HDR 中不会出现。
  因此公开包默认 `gallery=off`，避免 Gallery 代理覆盖带装饰的原生预览。

## 安装

1. 安装与游戏 2.31 兼容的 RED4ext。
2. 关闭游戏和启动器。
3. 把 ZIP 内全部内容解压到游戏根目录；最终应存在：

```text
Cyberpunk 2077\red4ext\plugins\CyberpunkPhotoModeHDR\
  CyberpunkPhotoModeHDR.dll
  CyberpunkPhotoModeHDRWorker.exe
  CyberpunkPhotoModeHDR.ini
```

4. 在游戏中使用 HDR10 PQ，进入原生拍照模式并按游戏自己的拍照键。
5. 原生保存完成后在拍照模式中短暂停留，等待下一帧提交。MOD 会按本机实际
   渲染耗时等待，不要求固定秒数。

## 输出位置

```text
%USERPROFILE%\Pictures\Cyberpunk 2077\photomode_*_HDR_忠实.UltraHDR.jpg
%USERPROFILE%\Pictures\Cyberpunk 2077\photomode_*_HDR_浓郁.UltraHDR.jpg
```

支持 Ultra HDR/gain map 的手机或软件显示 HDR；普通 JPEG 查看器会显示同一
文件内的 SDR 降级版本，不需要另存一份普通照片。

之所以选择这种格式，是因为它在当前常见方案中提供了很实用的“兼容性降级”：
支持 gain map 时显示 HDR，不支持时仍是能直接打开的普通 JPEG。它不是无损
母版，网站重压缩可能丢失 gain map，不同查看器也仍会 tone mapping；NVIDIA
JXR、Steam AVIF、原生 PNG、EXR 和桌面截图各有更合适的用途。完整、非拉踩的
优缺点与选择建议见 `docs/FORMAT-CHOICE.md`。

## 配置

编辑 `red4ext\plugins\CyberpunkPhotoModeHDR\CyberpunkPhotoModeHDR.ini`：

```ini
[Output]
mode=faithful
gallery=off
```

`mode`：

- `faithful`：只输出“忠实”（默认）；
- `rich`：只输出“浓郁”；
- `both`：一次 GPU 读回后在 CPU 上依次输出两张。

`gallery`：

- `off`：保留游戏原生 Gallery PNG（v0.1 默认）；
- `faithful` / `rich`：用相应预设的 SDR 预览替换 Gallery PNG。

启用 Gallery 代理时，原 PNG 会先逐字节备份到：

```text
%USERPROFILE%\Pictures\Cyberpunk 2077\.CyberpunkPhotoModeHDR\OriginalNativePNG\
```

但 v0.1 代理不含贴纸/相框，使用这些装饰时请保持 `gallery=off`。

## 已验证能力

- 游戏原生按钮触发；
- 当前游戏分辨率 FP16 读回，本机实测 2560x1600；
- 每次快门读取运行时纸白与峰值，不写死参考机 HDR 校准；
- 等待同次原生 PNG 已关闭并具有完整 `IEND`，避免捕获 DLSS/TAA/RR/PT
  时间历史过渡帧；
- `忠实`、`浓郁`、单次双输出；
- Ultra HDR JPEG 普通 JPEG 降级兼容；
- 可选 Gallery 代理与可恢复原 PNG 备份。

## 卸载与诊断

关闭游戏后删除这一精确目录即可卸载：

```text
Cyberpunk 2077\red4ext\plugins\CyberpunkPhotoModeHDR\
```

卸载不会删除已经生成的照片或原 PNG 备份。诊断日志位于：

```text
Cyberpunk 2077\red4ext\logs\cyberpunkphotomodehdr-*.log
Cyberpunk 2077\red4ext\plugins\CyberpunkPhotoModeHDR\CyberpunkPhotoModeHDRWorker.log
%USERPROFILE%\Pictures\Cyberpunk 2077\.CyberpunkPhotoModeHDR\
```

报告 Bug 时请附游戏版本、显卡、驱动、分辨率、HDR 模式、渲染模式、上述日志
以及崩溃 ReportQueue 路径；不要只提供“照片不对”。

第三方组件及许可证见 `THIRD-PARTY-NOTICES.txt` 和 `licenses\`。

## 可选支持

如果这个项目对你有用，可以自愿通过 [Ko-fi（全球）](https://ko-fi.com/nofjmt)
或 [爱发电（中国用户）](https://afdian.com/a/nofjmt) 支持。赞助与下载、功能和
问题反馈无关。

## 有限源码与许可证

本项目不是 MIT 项目，也不是 OSI 定义下的开源软件。原创材料按
`PolyForm Noncommercial License 1.0.0` 以 source-available 方式提供，
允许范围以 `LICENSE.md` 正文为准。公开仓库只提供用于审计原生拍照模式接入
边界的有限源码；完整版本适配、资源识别、读回、色彩和编码实现不公开。
详细边界见 `SOURCE-AVAILABLE-NOTICE.md`。

## 近期可能改进

后续只承诺继续验证和优化，不预告未经证实的大功能。当前关注点包括更多硬件/
渲染模式兼容性、贴纸和相框、Gallery 刷新稳定性、诊断信息以及在不破坏时序门
的前提下减少不必要的等待。没有发布日期保证。
