# v0.1 user-approved samples

The final validation sample came from the second shutter of the exact v0.1
owner validation run. The other two files came from one earlier native Photo
Mode shutter and were selected as the public preset comparison pair.

| Preset | File | SHA-256 |
| --- | --- | --- |
| Faithful / 忠实 final validation | `v0.1-faithful-final-validation.UltraHDR.jpg` | `31D34442AC90DFD67A3AD490F3B6908DBCEA2F34BB0414B9634B7025D5DB7A6F` |
| Faithful / 忠实 | `v0.1-faithful-car.UltraHDR.jpg` | `98E50D9A8D8229F2A6B72F575C8D09F2B96A12E12EBA4E174C32ADBF393726A6` |
| Rich / 浓郁 | `v0.1-rich-car.UltraHDR.jpg` | `9B71EBA44654A7E3A9B559E8CB456B1D42E926DB11BB0DB9E175A026088A890A` |

All are 2560x1600 Ultra HDR JPEGs and pass the libultrahdr 2.0.2 gain-map
probe. A viewer without Ultra HDR support displays the embedded SDR fallback;
a compatible phone or viewer may show additional HDR gain. Hosting services
may re-encode uploaded images and remove the gain map, so the original files
are retained here as downloadable samples.
