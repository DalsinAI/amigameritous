/* Meritous keeps big arrays on the stack: main() alone takes 1.2 MB of
 * locals (the title screen's), mapgen.c's queue 40 KB. A Shell gives 4 KB;
 * libnix's startup sets this much up instead.
 * The AmiCradle Team. GPL 3, like Meritous. */
unsigned long __stack = 2 * 1024 * 1024;
