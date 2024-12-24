#pragma once

#include <ncurses.h>
#include <curses.h> // For Windows compatibility.

using namespace std;

namespace nhkltui {
  /**
   * Weather or not to use the default options.
   */
  bool use_default_options = true;

  /**
   * The `Options` struct is used to configure the startup of the application.
   *
   * PARAMS:
   *   `has_banner`: If true, the application will print the given banner at
   *   startup. This is useful for multitools apps. Defaults to false.
   *
   *   `raw`: If true, the application will not do any processing of the input.
   *   Defaults to false.
   *
   *   `echo_chars`: If true, the application will echo the typed characters.
   *   Defaults to false.
   *
   *   `safe`: If true, the nhkltui will adapt to every terminal
   *   (this makes it more slow). Defaults to true.
   *
   *   `banner`: The banner to print at startup. Defaults to "" (empty string).
   *
   *   `keypad`: If true, the application
   *   will use special keys. Defaults to true.
   *
   */
  struct Options {
    bool has_banner;
    bool raw;
    bool echo_chars;
    bool safe;
    char *banner;
    bool keypad;
  };

  /**
   * The default options for nhkltui. (Explained in the `Options` struct)
   */
  const Options DEFAULT_OPTIONS = {.has_banner = false,
                                   .raw = false,
                                   .echo_chars = false,
                                   .safe = true,
                                   .banner = "",
                                   .keypad = true};

  void init(Options opts) {
    initscr();

    if (use_default_options) {
      noecho();
      cbreak();
      keypad(stdscr, true);
    } else {
      if (opts.raw) {
        raw();
      }
      if (opts.echo_chars) {
        echo();
      }
      if (opts.has_banner) {
        move(0, 0);
        addstr(opts.banner); // NOTE: Use addstr() as it handles multi-line strings better.
        refresh();
      }
    }
  }
};
