#!/bin/bash

valgrind --leak-check=full --show-leak-kinds=all --suppressions=supress_vgrind.txt --log-file=log.txt ./2048
