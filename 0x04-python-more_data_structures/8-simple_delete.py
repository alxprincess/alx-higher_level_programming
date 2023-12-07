#!/usr/bin/python3
def simple_delete(a_dictionary, key=""):
    a_dictionary.pop(key, None)
    return a_dictionary

if __name__ == "__main__":
    def print_sorted_dictionary(a_dictionary):
        for key in sorted(a_dictionary.keys()):
            print("{}: {}".format(key, a_dictionary[key]))
