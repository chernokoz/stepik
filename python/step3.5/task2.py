import sys

if __name__ == "__main__":
    if len(sys.argv) > 1:
        file_name, *scr_args = sys.argv
        print(*scr_args)
