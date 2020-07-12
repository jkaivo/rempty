rempty
------

This utility removes all empty directories under the tree(s) specified on
the command line. It's useful for cleaning up after inconsiderate programs
that create empty directories as a matter of course. For example:

    rempty "${XDG_CONFIG_HOME:-~/.config}" "${XDG_DATA_HOME:-~/.local}" "${XDG_CACHE_HOME:-~/.cache}"

This can clean up after many messy programs that otherwise conform to the XDG
base directory specification.
