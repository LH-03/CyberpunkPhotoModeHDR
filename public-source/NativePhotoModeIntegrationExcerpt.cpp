// Copyright (c) 2026 CyberpunkPhotoModeHDR Project contributors.
// PolyForm Noncommercial License 1.0.0. See LICENSE.md.
//
// SANITIZED, NON-BUILDABLE AUDIT EXCERPT.
// This shows the production control boundary without publishing the private
// version adapter, exact hook/signature data, D3D12 resource discovery,
// descriptor topology, readback implementation, or encoder/color pipeline.

#include "PhotoModeCaptureContract.hpp"

namespace cyberpunk_photomode_hdr::audit_excerpt
{
using public_contract::FrameEligibility;
using public_contract::IsEligible;

// The shipping adapter observes the semantic action TakeScreenshot_HiRes.
// It never consumes or replaces the action: the original game handler is
// forwarded first, preserving Cyberpunk's blackout, notification, and PNG.
void OnNativeTakeScreenshotHiRes(void* gameActionContext)
{
    const auto shotTicket = ArmOneShotTicketFromActivePhotoMode();
    ForwardToOriginalGameHandler(gameActionContext);
    BeginWatchingTheSameShotNativePng(shotTicket);
}

// The watcher does not use a guessed fixed delay. The same-shot PNG must be
// exclusively openable and end in a valid PNG IEND before the ticket advances.
void OnNativePngObservedComplete(std::uint64_t shotTicket)
{
    MarkNextExactInternalPhotoFrameEligible(shotTicket);
}

// "Exact internal branch" is a version-qualified, current-resolution,
// UI-free RGBA16F Photo Mode image. It is not the desktop or swap chain.
void OnInternalPhotoModeFrame(const InternalFrameView& frame)
{
    const FrameEligibility gate{
        .nativePngCanBeOpenedExclusively = NativePngIsClosed(frame.ticket),
        .nativePngHasCompleteIend = NativePngHasIend(frame.ticket),
        .isInternalUiFreePhotoModeFp16Branch = IsQualifiedPhotoBranch(frame),
        .dimensionsMatchActiveRender = MatchesActiveRenderSize(frame),
        .runtimeOutputIsHdr10Pq = RuntimeOutputIsHdr10Pq(frame),
    };

    if (!IsEligible(gate))
        return;

    // Production code schedules an asynchronous GPU readback, releases the
    // one-shot gate, and sends CPU-owned staging data plus same-frame runtime
    // paper-white/peak metadata to the worker. Those implementations are not
    // part of the public source subset.
    QueuePrivateReadbackAndCpuEncode(frame);
}
} // namespace cyberpunk_photomode_hdr::audit_excerpt
