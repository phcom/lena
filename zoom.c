#include <stdio.h>
#include "lib_ppm.h"

int main(void)
{
	struct image_s data;
	struct image_s *image = &data;
	int i, j, r;

	struct image_s data_c;
	struct image_s *image_c = &data_c;

    r = read_ppm("lena.ppm", image);

    if (r == 0) {

        int new_width = image->width * 3;
        int new_height = image->height * 3;

        r = new_ppm(image_c, new_width, new_height);

        if (r == 0) {
            for (j = 0; j < new_height; j = j + 3) {
                for (i = 0; i < new_width; i = i + 3) {

                    int original_i = i / 3;
                    int original_j = j / 3;

                    int original_index = original_j * image->width + original_i;

					int top_side = j * new_width + i + 1;
					int top_left_corner = j * new_width + i;
					int top_right_corner = j * new_width + i + 2;

					int bottom_side = (j + 2) * new_width + i + 1;
					int bottom_left_corner = (j + 2) * new_width + i;
					int bottom_right_corner = (j + 2) * new_width + i + 2;
					
					int center = (j + 1) * new_width + i + 1;
					int left_side = (j + 1) * new_width + i;
					int right_side = (j + 1) * new_width + i + 2;


					if (image->pix[original_index].r >= 75 && image->pix[original_index].r <= 134)
					{
						image_c->pix[left_side].r = image->pix[original_index].r;
					}

					if (image->pix[original_index].g >= 75 && image->pix[original_index].g <= 134)
					{
						image_c->pix[center].g = image->pix[original_index].g;
					}
					
					if (image->pix[original_index].b >= 75 && image->pix[original_index].b <= 134)
					{
						image_c->pix[right_side].b = image->pix[original_index].b;
					}
				

					if (image->pix[original_index].r >= 135 && image->pix[original_index].r <= 179)
					{
						image_c->pix[top_left_corner].r = image->pix[original_index].r;
						image_c->pix[bottom_left_corner].r = image->pix[original_index].r;
					}
					
					if (image->pix[original_index].g >= 135 && image->pix[original_index].g <= 179)
					{
						image_c->pix[top_side].g = image->pix[original_index].g;
						image_c->pix[bottom_side].g = image->pix[original_index].g;
					}

					if (image->pix[original_index].b >= 135 && image->pix[original_index].b <= 179)
					{
						image_c->pix[top_right_corner].b = image->pix[original_index].b;
						image_c->pix[bottom_right_corner].b = image->pix[original_index].b;
					}


					if (image->pix[original_index].r >= 180 && image->pix[original_index].r <= 255)
					{
						image_c->pix[top_left_corner].r = image->pix[original_index].r;
						image_c->pix[left_side].r = image->pix[original_index].r;
						image_c->pix[bottom_left_corner].r = image->pix[original_index].r;
					}

					if (image->pix[original_index].g >= 180 && image->pix[original_index].g <= 255)
					{
						image_c->pix[top_side].g = image->pix[original_index].g;
						image_c->pix[center].g = image->pix[original_index].g;
						image_c->pix[bottom_side].g = image->pix[original_index].g;
					}

					if (image->pix[original_index].b >= 180 && image->pix[original_index].b <= 255)
					{
						image_c->pix[top_right_corner].b = image->pix[original_index].b;
						image_c->pix[right_side].b = image->pix[original_index].b;
						image_c->pix[bottom_right_corner].b = image->pix[original_index].b;
					}
                }
            }
            write_ppm("t1.ppm", image_c);
            free_ppm(image_c);
			free_ppm(image);
        }
    }
	return 0;
}