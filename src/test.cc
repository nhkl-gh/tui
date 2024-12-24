#include "nhkltui.h"

using namespace nhkltui;

int main(int argc, char **argv) {
	Options opts = Options{
		.has_banner = true,
		.raw = false,
		.echo_chars = false,
		.safe = false,
		.banner = " | NHKLTUI TEST | ",
	  .keypad = false,
	};
	init(opts);
}
