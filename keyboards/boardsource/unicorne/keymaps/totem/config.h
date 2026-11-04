// Copyright 2026 Jack Hu (@jh242)
#pragma once

/*
 * Totem HRM (same knobs as Charybdis Mini QMK):
 *   PERMISSIVE_HOLD → mod on nested opposite release (or TAPPING_TERM)
 *   CHORDAL_HOLD    → same-hand HRM+letter forced tap; HRM+HRM still ok
 *   FLOW_TAP / QUICK_TAP → mid-burst / retap hygiene
 *   (no HOLD_ON_OTHER_KEY_PRESS — steals opposite-hand rolls)
 *
 * Layer thumbs are plain MO() — instantaneous, not mod-taps / LT.
 * If layers still feel "sticky", it's usually roll timing (layer key must
 * be down before the dual-key) or RGB load — not TAPPING_TERM on MO.
 */
#define TAPPING_TERM 200
#define QUICK_TAP_TERM 175
#define FLOW_TAP_TERM 100
#define CHORDAL_HOLD
#define PERMISSIVE_HOLD

#define DEBOUNCE 3

#define OLED_TIMEOUT 30000
/* Right half needs to know about keypresses to keep its OLED awake. */
#define SPLIT_ACTIVITY_ENABLE
