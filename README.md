# stream-bridge

A lightweight C++ stream wrapper using the Bridge (PIMPL) design pattern.

---

## Overview

This library provides lightweight replacements for the standard C++ stream headers:

- `<iostream>`
- `<iomanip>`
- `<sstream>`
- `<fstream>`

You can replace these with:

- `"iostream-bridge.h"`
- `"sstream-bridge.h"`
- `"fstream-bridge.h"`

The implementation uses the **Bridge / PIMPL idiom**, and simply forwards calls to the corresponding functions in the standard C++ stream library.

---

## Why use this?

The standard `<iostream>` headers are heavy and can lead to long compile times in large projects.

The `stream-bridge` library:

- Reduces compile times by isolating stream dependencies.
- Uses fewer templates and is less generic, making it faster to compile.
- Trades a bit of runtime performance (due to indirection) for better build performance.

This makes it useful for large C++ projects with many translation units including stream headers.

---

## Limitations

- Not as feature-complete or generic as the standard C++ stream library.
- Slight runtime overhead due to the extra layer of indirection.
- Currently limited in sc
