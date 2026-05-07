"""Console entry point for the signal_logger reader REPL."""

import sys

import signal_logger


def main() -> None:
    silo = None  # noqa: F841
    if len(sys.argv) > 1:
        silo = signal_logger.Silo(sys.argv[1])  # noqa: F841
        if len(sys.argv) > 2:
            print("Other arguments {} have been ignored".format(sys.argv[2:]))
        print("Read silo with {} keys.\n".format(len(silo.data)))
    else:
        print("Usage: signal_logger_reader path_to_file.silo")

    try:
        from IPython import embed
    except ImportError:
        print(
            "IPython is not installed; install it (or signal_logger_python[shell]) " "to drop into an interactive REPL."
        )
        return
    embed(colors="neutral")


if __name__ == "__main__":
    main()
