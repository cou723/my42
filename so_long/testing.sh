#!/bin/sh
echo "<<SAMPLE1>>"
./so_long ./maps/sample1.ber
echo "<<SAMPLE2>>"
./so_long ./maps/sample2.ber
echo "<<ORI_SAMPLE>>"
./so_long ./maps/original_sample.ber
echo "<<DUPLICATION_PLAYER>>"
./so_long ./maps/error_maps/duplication_player.ber
echo "<<EMPTY>>"
./so_long ./maps/error_maps/empty.ber
./so_long ./maps/error_maps/empty_line.ber
./so_long ./maps/error_maps/empty_first_line.ber
./so_long ./maps/empty_end_line.ber
echo "<<INVALID_CHAR>>"
./so_long ./maps/error_maps/invalid_char.ber
echo "<<NOT_EXIST_EXIT>>"
./so_long ./maps/error_maps/not_exist_exit.ber
echo "<<NOT_EXIST_PLAYER>>"
./so_long ./maps/error_maps/not_exist_player.ber
echo "<<NOT_EXIST_COLLECTIVE>>"
./so_long ./maps/error_maps/not_exist_collective.ber
echo "<<NOT_RECT>>"
./so_long ./maps/error_maps/not_rect.ber
echo "<<NOT_WALLED1>>"
./so_long ./maps/error_maps/not_walled1.ber
echo "<<NOT_WALLED2>>"
./so_long ./maps/error_maps/not_walled2.ber

# valgrind --leak-check=full ./so_long ./maps/sample1.ber
# valgrind --leak-check=full ./so_long ./maps/sample2.ber
# valgrind --leak-check=full ./so_long ./maps/error_maps/duplication_player.ber
# valgrind --leak-check=full ./so_long ./maps/error_maps/empty.ber
# valgrind --leak-check=full ./so_long ./maps/error_maps/invalid_char.ber
# valgrind --leak-check=full ./so_long ./maps/error_maps/not_exist_exit.ber
# valgrind --leak-check=full ./so_long ./maps/error_maps/not_exist_player.ber
# valgrind --leak-check=full ./so_long ./maps/error_maps/not_exist_collective.ber
# valgrind --leak-check=full ./so_long ./maps/error_maps/not_rect.ber
# valgrind --leak-check=full ./so_long ./maps/error_maps/not_walled1.ber
# valgrind --leak-check=full ./so_long ./maps/error_maps/not_walled2.ber