pub type Image {
  Image(w: Int, h: Int, data: ImageData, channels: Int)
}

pub type ImageData =
  String

pub type Path =
  String

@external(c, "glimage", "glimage_stbi_load")
pub fn load_image(filename: Path) -> Image

@external(c, "glimage", "glimage_stbi_write_png")
pub fn save_image(image: Image, filename: Path) -> Result(Bool, String)

pub fn print_image_info(img: Image) {
  echo img.h
  echo img.w
  echo img.channels
}

pub fn update_img_data(img: Image, data: ImageData) {
  Image(w: img.w, h: img.h, data: data, channels: img.channels)
}
