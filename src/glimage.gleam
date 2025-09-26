import gleam/io
import gleam/list
import gleam/string
import glimage_bindings.{type Image}

pub fn main() {
  let my_gleam_img: Image = glimage_bindings.load_image("gleam.png")
  glimage_bindings.print_image_info(my_gleam_img)

  let new_data: glimage_bindings.ImageData =
    my_gleam_img.data
    |> string.to_graphemes
    |> list.reverse
    |> string.concat
  let new_image = glimage_bindings.update_img_data(my_gleam_img, new_data)
  let saved = new_image |> glimage_bindings.save_image("gleam_new.png")
  case saved {
    Ok(_) -> io.println("Image succesfully saved")
    Error(e) -> io.println("There was an error saving the image: " <> e)
  }
}
