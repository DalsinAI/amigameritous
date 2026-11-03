# Amiga port intake: Meritous

- Port Atlas: [g-meritous](https://www.amicradle.com/ports/#g-meritous)
- Priority: `P2`
- Atlas decision: `evaluate`
- Upstream source: `https://github.com/bart9h/meritous`
- Atlas source pin: `Unverified`
- Imported commit: `d2e969fe432c01a350fee7af799232fa52e2aec5`
- Rights state: `review`

## Target contract

Primary target: AmigaOS 3.x / AmiCradle AC090 / Motorola 68040 + FPU.

Use the OPEN platform libraries where applicable: OpenGPU, OpenAudio/OpenAHI, OpenInput, OpenSocket and measured OpenMulticore work. Preserve a correct 68040 fallback and do not assume Roadshow.

No build, runtime, playability or release claim is made by this source-intake commit. Upstream submodules are not initialised. Original commercial game data remains external.

## Rights and data boundary

review; Confirm source/data licences before release.

## Build (AmigaOS 3.x, 68040 + FPU, on acsdl12)

    make -f amiga/Makefile.amigaos \
        STOVE=/path/to/openamigagcc-16.2.0-open4-x86_64-linux \
        NDK=/path/to/gfopensdk/OpenNDK/Include_H \
        ACSDL=/path/to/amicradle-guest/gameports/acsdl12 \
        ZLIB=/path/to/zlib-1.3.1

acsdl12 (amicradle-guest `gameports/acsdl12`, built with its own
`Makefile.amigaos`) is SDL 1.2, SDL_image and SDL_mixer on ACGame and AHI. zlib's
gz files are built in here for the saved games. This gives
`build/amigaos/Meritous/` with the program and `dat/` beside it; run it from
that drawer. 640x480 in 256 colours, RTG or AGA (`ENV:ACGame/Display`).

Changes for the Amiga: a 2 MB stack (`amiga/stack.c`: `main()` keeps 1.2 MB of
locals) and 22050 Hz sound. Only the `.MOD` tunes play; the `.XM` and `.S3M`
ones are skipped, so the title and some rooms are silent.

State (3 November 2026): in an AmiCradle lab instance (OpenKick ROM, 68040 +
FPU). RTG: title, new game, map generation, walking, the circuit charge and its
sound. AGA: title and new game run, but only the top-left part of the 640x480
picture is shown. Not yet run on a real 68040.

