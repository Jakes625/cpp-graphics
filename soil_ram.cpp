/* load an image as a heightmap, forcing greyscale (so channels should be 1) */
int width, height, channels;
unsigned char *ht_map = SOIL_load_image
	(
		"terrain.tga",
		&width, &height, &channels,
		SOIL_LOAD_L
	);
	
/* save that image as another type */
int save_result = SOIL_save_image
	(
		"new_terrain.dds",
		SOIL_SAVE_TYPE_DDS,
		width, height, channels,
		ht_map
	);
	
/* save a screenshot of your awesome OpenGL game engine, running at 1024x768 */
save_result = SOIL_save_screenshot
	(
		"awesomenessity.bmp",
		SOIL_SAVE_TYPE_BMP,
		0, 0, 1024, 768
	);

/* loaded a file via PhysicsFS, need to decompress the image from RAM, */
/* where it's in a buffer: unsigned char *image_in_RAM */
GLuint tex_2d_from_RAM = SOIL_load_OGL_texture_from_memory
	(
		image_in_RAM,
		image_in_RAM_bytes,
		SOIL_LOAD_AUTO,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_COMPRESS_TO_DXT
	);
	
	
/* heres the params for load OGL texture */
unsigned int
	SOIL_load_OGL_texture_from_memory
	(
		const unsigned char *const buffer,
		int buffer_length,
		int force_channels,
		unsigned int reuse_texture_ID,
		unsigned int flags
	);
	
/* done with the heightmap, free up the RAM */
SOIL_free_image_data( ht_map );
