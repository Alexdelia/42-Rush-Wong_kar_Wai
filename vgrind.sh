#!/bin/bash

valgrind --leak-check=full --show-leak-kinds=all --log-file=log.txt ./game_2048
