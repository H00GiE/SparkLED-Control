/*
   Tree v2: https://github.com/evilgeniuslabs/tree-v2
   Copyright (C) 2016 Jason Coon

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
const uint8_t radii[NUM_LEDS] = {
  255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 255, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 219, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 183, 147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 147, 111, 111, 111, 111, 111, 111, 111, 111, 111, 75, 75, 75, 75, 75, 75, 39, 39, 39, 39, 3, 3
};
const uint8_t angles[NUM_LEDS] = {
  0, 9, 18, 28, 37, 47, 56, 66, 75, 85, 94, 103, 113, 122, 132, 141, 151, 160, 170, 179, 188, 198, 207, 217, 226, 236, 245, 0, 11, 22, 33, 44, 55, 66, 77, 88, 99, 110, 121, 133, 144, 155, 166, 177, 188, 199, 210, 221, 232, 243, 0, 14, 28, 42, 56, 70, 85, 99, 113, 127, 141, 155, 170, 184, 198, 212, 226, 240, 0, 19, 39, 58, 78, 98, 117, 137, 156, 176, 196, 215, 235, 0, 28, 56, 85, 113, 141, 170, 198, 226, 0, 42, 85, 127, 170, 212, 0, 63, 127, 191, 0, 127
};
const uint8_t levelCount = 8;
const uint8_t ledsPerLevel[levelCount] = {
  27, 23, 18, 13, 9, 6, 4, 2
};
const uint16_t levelStart[levelCount] = {
  0, 27, 50, 68, 81, 90, 96, 100
};
const uint16_t levelEnd[levelCount] = {
  26, 49, 67, 80, 89, 95, 99, 101
};
const uint8_t levels[NUM_LEDS] = {
  0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 5, 5, 5, 5, 5, 5, 6, 6, 6, 6, 7, 7
};
const uint8_t zCoords[NUM_LEDS] = {
  0, 2, 5, 7, 10, 12, 15, 17, 20, 22, 25, 27, 30, 32, 35, 37, 40, 42, 45, 47, 50, 52, 55, 57, 60, 62, 65, 67, 70, 72, 75, 77, 80, 82, 85, 87, 90, 92, 95, 97, 100, 102, 105, 107, 110, 112, 115, 117, 120, 122, 125, 127, 130, 132, 135, 137, 140, 142, 145, 147, 150, 152, 155, 157, 160, 162, 165, 167, 170, 172, 175, 177, 180, 182, 185, 187, 190, 192, 195, 197, 200, 202, 205, 207, 210, 212, 215, 217, 220, 222, 225, 227, 230, 232, 235, 237, 240, 242, 245, 247, 250, 252
};
const uint8_t xCoords[NUM_LEDS] = {
  255, 251, 241, 225, 204, 178, 150, 121, 92, 65, 41, 22, 9, 2, 1, 8, 20, 39, 62, 89, 118, 147, 175, 201, 223, 240, 250, 237, 232, 221, 202, 178, 150, 121, 92, 65, 44, 28, 20, 19, 27, 42, 63, 89, 118, 148, 176, 200, 219, 232, 219, 213, 197, 173, 144, 112, 83, 58, 42, 37, 42, 57, 81, 110, 142, 171, 196, 212, 201, 192, 169, 137, 102, 73, 57, 56, 72, 100, 135, 168, 191, 183, 170, 137, 100, 76, 76, 99, 136, 169, 165, 146, 109, 91, 108, 145, 147, 128, 109, 127, 129, 127
};
const uint8_t yCoords[NUM_LEDS] = {
  128, 157, 184, 209, 229, 244, 252, 254, 249, 238, 221, 198, 172, 144, 114, 86, 59, 36, 19, 6, 1, 2, 10, 24, 44, 68, 95, 128, 157, 184, 207, 224, 234, 236, 230, 217, 197, 172, 144, 114, 85, 60, 39, 25, 19, 20, 30, 46, 69, 96, 128, 159, 186, 206, 217, 217, 207, 187, 160, 129, 98, 70, 49, 38, 38, 48, 67, 94, 128, 161, 187, 200, 196, 176, 146, 111, 80, 60, 55, 67, 92, 128, 163, 182, 175, 147, 109, 80, 73, 91, 128, 159, 160, 128, 96, 95, 128, 146, 128, 109, 128, 128
};
uint16_t getNearestToAngleAndLevel(uint8_t angle, uint8_t level) {
  uint8_t smallestDifference = 255;
  uint8_t nearestIndex = 0;

  for (uint16_t i = 0; i < NUM_LEDS; i++) {
    if (levels[i] != level)
      continue;

    uint8_t currentAngle = angles[i];

    uint8_t difference = abs(currentAngle - angle);

    if (difference > smallestDifference)
      continue;
    else if (difference == smallestDifference && random8() > 127)
      continue;

    smallestDifference = difference;
    nearestIndex = i;
  }

  return nearestIndex;
}
