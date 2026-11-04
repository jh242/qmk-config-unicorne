# qmk-config-unicorne

QMK userspace for **Boardsource Unicorne** (RP2040) — Totem keymap ported from
[`jh242/zmk-config`](https://github.com/jh242/zmk-config) / Charybdis Mini.

Forked from the [`qmk/qmk_userspace`](https://github.com/qmk/qmk_userspace) template.

## Layout

```
| Tab |  Q  |  W  |  E  |  R  |  T  |   |  Y  |  U  |  I  |  O  |  P  |  \  |
|  `  |A/GUI|S/ALT|D/CTL|F/SFT|  G  |   |  H  |J/SFT|K/CTL|L/ALT|;/GUI|  '  |
| Sft |  Z  |  X  |  C  |  V  |  B  |   |  N  |  M  |  ,  |  .  |  /  | Sft |
                    | NAV | Ent | Bspc|   | Spc | Esc | SYM |
```

| Layer | How | Notes |
|-------|-----|-------|
| **BASE** | default | Home-row mods (urob-style CHORDAL + FLOW + PERMISSIVE) |
| **NAV** | hold left-outer thumb (`MO`) | Numbers + vim arrows / Home End Pg |
| **SYM** | hold right-outer thumb (`MO`) | Brackets / operators |
| **NUM** | NAV + SYM | F-keys, numpad, `QK_BOOT` / `EE_CLR` |

RGB is compiled out.

**Combos:** `J`+`K` → Esc · `Z`+`X` → Caps Word

Layer thumbs are plain `MO()` (instant). They are **not** mod-taps — if a layer
still feels delayed, keep the thumb fully down before the second key (QMK roll
ordering), or we can tune debounce/RGB next.

## Flash

1. Actions → download the UF2 from the latest run / Release, **or** build locally:
   ```bash
   qmk config user.overlay_dir="$(realpath .)"
   qmk compile -kb boardsource/unicorne -km totem
   ```
2. Hold **BOOT** (right button), tap **RESET** (left) → `RPI-RP2`
3. Drag the UF2 onto the drive. Flash **each half** the first time.
