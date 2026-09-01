// Copyright (c) 2026 CyberpunkPhotoModeHDR Project contributors.
// PolyForm Noncommercial License 1.0.0. See LICENSE.md.
//
// Public audit contract. This is intentionally independent of the private
// game-version adapter, D3D12 discovery layer, readback implementation, and
// Ultra HDR encoder. It documents the gates enforced by the shipping design.

#pragma once

#include <cstdint>

namespace cyberpunk_photomode_hdr::public_contract
{
enum class Preset : std::uint8_t
{
    faithful,
    rich,
    both
};

enum class GalleryMode : std::uint8_t
{
    off,
    faithful,
    rich
};

enum class CapturePhase : std::uint8_t
{
    idle,
    native_shutter_forwarded,
    native_png_complete,
    internal_frame_eligible,
    gpu_readback_pending,
    cpu_encode_pending,
    complete,
    failed
};

struct FrameEligibility final
{
    bool nativePngCanBeOpenedExclusively{};
    bool nativePngHasCompleteIend{};
    bool isInternalUiFreePhotoModeFp16Branch{};
    bool dimensionsMatchActiveRender{};
    bool runtimeOutputIsHdr10Pq{};
};

[[nodiscard]] constexpr bool IsEligible(const FrameEligibility& value) noexcept
{
    return value.nativePngCanBeOpenedExclusively &&
           value.nativePngHasCompleteIend &&
           value.isInternalUiFreePhotoModeFp16Branch &&
           value.dimensionsMatchActiveRender &&
           value.runtimeOutputIsHdr10Pq;
}

struct ShotTicket final
{
    std::uint64_t id{};
    CapturePhase phase{CapturePhase::idle};
    std::uint32_t width{};
    std::uint32_t height{};
    float runtimePaperWhiteNits{};
    float runtimePeakNits{};
    Preset preset{Preset::faithful};
    GalleryMode gallery{GalleryMode::off};
};
} // namespace cyberpunk_photomode_hdr::public_contract
