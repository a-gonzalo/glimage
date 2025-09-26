#include <builtin.h>

typedef struct Tuple2_String_String Tuple2_String_String;
typedef struct glimage_bindings_Image glimage_bindings_Image;
typedef struct T_List_UtfCodepoint List_UtfCodepoint;
enum E_List {
  E_Empty,
  E_Cons
};
union U_List_UtfCodepoint {
  struct Empty_UtfCodepoint *Empty;
  struct Cons_UtfCodepoint *Cons;
};
struct T_List_UtfCodepoint {
  enum E_List tag;
  union U_List_UtfCodepoint val;
};
typedef struct T_Result_Bool_String Result_Bool_String;
enum E_Result {
  E_Ok,
  E_Error
};
union U_Result_Bool_String {
  struct Ok_Bool_String *Ok;
  struct Error_Bool_String *Error;
};
struct T_Result_Bool_String {
  enum E_Result tag;
  union U_Result_Bool_String val;
};
typedef struct T_Result_Tuple2_String_String_Nil Result_Tuple2_String_String_Nil;
union U_Result_Tuple2_String_String_Nil {
  struct Ok_Tuple2_String_String_Nil *Ok;
  struct Error_Tuple2_String_String_Nil *Error;
};
struct T_Result_Tuple2_String_String_Nil {
  enum E_Result tag;
  union U_Result_Tuple2_String_String_Nil val;
};
typedef struct T_List_String List_String;
union U_List_String {
  struct Empty_String *Empty;
  struct Cons_String *Cons;
};
struct T_List_String {
  enum E_List tag;
  union U_List_String val;
};
struct Tuple2_String_String {
  String field0;
  String field1;
};
struct glimage_bindings_Image {
  Int w;
  Int h;
  String data;
  Int channels;
};
struct Empty_UtfCodepoint {
};
struct Cons_UtfCodepoint {
  UtfCodepoint item;
  List_UtfCodepoint next;
};
struct Ok_Bool_String {
  Bool value;
};
struct Error_Bool_String {
  String value;
};
struct Ok_Tuple2_String_String_Nil {
  Tuple2_String_String value;
};
struct Error_Tuple2_String_String_Nil {
  Nil value;
};
struct Empty_String {
};
struct Cons_String {
  String item;
  List_String next;
};


Tuple2_String_String new_Tuple2_String_String(String field0, String field1);
Bool eq_Tuple2_String_String(Tuple2_String_String a, Tuple2_String_String b);
Bool lt_Tuple2_String_String(Tuple2_String_String a, Tuple2_String_String b);
String inspect_Tuple2_String_String(Tuple2_String_String value);
glimage_bindings_Image new_glimage_bindings_Image(Int w, Int h, String data, Int channels);
Bool eq_glimage_bindings_Image(glimage_bindings_Image a, glimage_bindings_Image b);
Bool lt_glimage_bindings_Image(glimage_bindings_Image a, glimage_bindings_Image b);
String inspect_glimage_bindings_Image(glimage_bindings_Image value);
extern const List_UtfCodepoint new_Empty_UtfCodepoint;
List_UtfCodepoint new_Cons_UtfCodepoint(UtfCodepoint item, List_UtfCodepoint next);
Bool eq_List_UtfCodepoint(List_UtfCodepoint a, List_UtfCodepoint b);
Bool lt_List_UtfCodepoint(List_UtfCodepoint a, List_UtfCodepoint b);
String inspect_List_UtfCodepoint(List_UtfCodepoint value);
Result_Bool_String new_Ok_Bool_String(Bool value);
Result_Bool_String new_Error_Bool_String(String value);
Bool eq_Result_Bool_String(Result_Bool_String a, Result_Bool_String b);
Bool lt_Result_Bool_String(Result_Bool_String a, Result_Bool_String b);
String inspect_Result_Bool_String(Result_Bool_String value);
Result_Tuple2_String_String_Nil new_Ok_Tuple2_String_String_Nil(Tuple2_String_String value);
Result_Tuple2_String_String_Nil new_Error_Tuple2_String_String_Nil(Nil value);
Bool eq_Result_Tuple2_String_String_Nil(Result_Tuple2_String_String_Nil a, Result_Tuple2_String_String_Nil b);
Bool lt_Result_Tuple2_String_String_Nil(Result_Tuple2_String_String_Nil a, Result_Tuple2_String_String_Nil b);
String inspect_Result_Tuple2_String_String_Nil(Result_Tuple2_String_String_Nil value);
extern const List_String new_Empty_String;
List_String new_Cons_String(String item, List_String next);
Bool eq_List_String(List_String a, List_String b);
Bool lt_List_String(List_String a, List_String b);
String inspect_List_String(List_String value);
Nil gleam_io_do_print(String s);
Result_Bool_String glimage_stbi_write_png(glimage_bindings_Image image, String filename);
Result_Tuple2_String_String_Nil pop_grapheme_string(String string);
String append_string(String a, String b);
Nil print_string(String message);
glimage_bindings_Image glimage_stbi_load(String filename);
Int echo__Int(Int value);
Int glimage_bindings_print_image_info(glimage_bindings_Image img);
List_String gleam_string_append_pairs(List_String strings);
String gleam_string_concat(List_String strings);
List_String gleam_list_reverse_and_prepend_String(List_String prefix, List_String suffix);
List_String gleam_list_reverse_String(List_String list);
List_String gleam_string_to_graphemes_loop(String string, List_String acc);
List_String gleam_string_to_graphemes(String string);
glimage_bindings_Image glimage_bindings_update_img_data(glimage_bindings_Image img, String data);
Nil gleam_io_println(String string);
Nil glimage_main();


Tuple2_String_String new_Tuple2_String_String(String field0, String field1) {
  return (Tuple2_String_String){.field0 = field0, .field1 = field1};
}
glimage_bindings_Image new_glimage_bindings_Image(Int w, Int h, String data, Int channels) {
  return (glimage_bindings_Image){.w = w, .h = h, .data = data, .channels = channels};
}
const List_UtfCodepoint new_Empty_UtfCodepoint = {.tag = E_Empty, .val = {0}};
List_UtfCodepoint new_Cons_UtfCodepoint(UtfCodepoint item, List_UtfCodepoint next) {
  struct Cons_UtfCodepoint *_ptr = malloc(sizeof(struct Cons_UtfCodepoint));
  *_ptr = (struct Cons_UtfCodepoint){.item = item, .next = next};
  return (List_UtfCodepoint){.tag = E_Cons, .val.Cons = _ptr};
}
Result_Bool_String new_Ok_Bool_String(Bool value) {
  struct Ok_Bool_String *_ptr = malloc(sizeof(struct Ok_Bool_String));
  *_ptr = (struct Ok_Bool_String){.value = value};
  return (Result_Bool_String){.tag = E_Ok, .val.Ok = _ptr};
}
Result_Bool_String new_Error_Bool_String(String value) {
  struct Error_Bool_String *_ptr = malloc(sizeof(struct Error_Bool_String));
  *_ptr = (struct Error_Bool_String){.value = value};
  return (Result_Bool_String){.tag = E_Error, .val.Error = _ptr};
}
Result_Tuple2_String_String_Nil new_Ok_Tuple2_String_String_Nil(Tuple2_String_String value) {
  struct Ok_Tuple2_String_String_Nil *_ptr = malloc(sizeof(struct Ok_Tuple2_String_String_Nil));
  *_ptr = (struct Ok_Tuple2_String_String_Nil){.value = value};
  return (Result_Tuple2_String_String_Nil){.tag = E_Ok, .val.Ok = _ptr};
}
Result_Tuple2_String_String_Nil new_Error_Tuple2_String_String_Nil(Nil value) {
  struct Error_Tuple2_String_String_Nil *_ptr = malloc(sizeof(struct Error_Tuple2_String_String_Nil));
  *_ptr = (struct Error_Tuple2_String_String_Nil){.value = value};
  return (Result_Tuple2_String_String_Nil){.tag = E_Error, .val.Error = _ptr};
}
const List_String new_Empty_String = {.tag = E_Empty, .val = {0}};
List_String new_Cons_String(String item, List_String next) {
  struct Cons_String *_ptr = malloc(sizeof(struct Cons_String));
  *_ptr = (struct Cons_String){.item = item, .next = next};
  return (List_String){.tag = E_Cons, .val.Cons = _ptr};
}
Int echo__Int(Int value) {
  String T0;
  T0 = inspect_Int(value);
  print_string(T0);
  print_string(new_String("\n", 1));
  return value;
}

Int glimage_bindings_print_image_info(glimage_bindings_Image img) {
  echo__Int(img.h);
  echo__Int(img.w);
  return echo__Int(img.channels);
}

List_String gleam_string_append_pairs(List_String strings) {
  List_String S0;
  S0 = strings;
  if (S0.tag == E_Empty) {
    return new_Empty_String;
  } else {
    Bool T0;
    if (S0.tag == E_Cons) {
      T0 = S0.val.Cons->next.tag == E_Empty;
    } else {
      T0 = False;
    }
    if (T0) {
      String x;
      x = S0.val.Cons->item;
      return new_Cons_String(x, new_Empty_String);
    } else {
      Bool T1;
      if (S0.tag == E_Cons) {
        T1 = S0.val.Cons->next.tag == E_Cons;
      } else {
        T1 = False;
      }
      if (T1) {
        String xV1;
        xV1 = S0.val.Cons->item;
        String y;
        y = S0.val.Cons->next.val.Cons->item;
        List_String xs;
        xs = S0.val.Cons->next.val.Cons->next;
        String T2;
        T2 = append_string(xV1, y);
        List_String T3;
        T3 = gleam_string_append_pairs(xs);
        return new_Cons_String(T2, T3);
      } else {
        panic_exit(new_String("No matching clause in gleam/string.append_pairs", 47));
      }
    }
  }
}

String gleam_string_concat(List_String strings) {
  List_String S0;
  S0 = strings;
  if (S0.tag == E_Empty) {
    return new_String("", 0);
  } else {
    Bool T0;
    if (S0.tag == E_Cons) {
      T0 = S0.val.Cons->next.tag == E_Empty;
    } else {
      T0 = False;
    }
    if (T0) {
      String x;
      x = S0.val.Cons->item;
      return x;
    } else {
      List_String xs;
      xs = S0;
      List_String T1;
      T1 = gleam_string_append_pairs(xs);
      return gleam_string_concat(T1);
    }
  }
}

List_String gleam_list_reverse_and_prepend_String(List_String prefix, List_String suffix) {
  List_String S0;
  S0 = prefix;
  if (S0.tag == E_Empty) {
    return suffix;
  } else {
    if (S0.tag == E_Cons) {
      String first;
      first = S0.val.Cons->item;
      List_String rest;
      rest = S0.val.Cons->next;
      List_String T0;
      T0 = new_Cons_String(first, suffix);
      return gleam_list_reverse_and_prepend_String(rest, T0);
    } else {
      panic_exit(new_String("No matching clause in gleam/list.reverse_and_prepend", 52));
    }
  }
}

List_String gleam_list_reverse_String(List_String list) {
  return gleam_list_reverse_and_prepend_String(list, new_Empty_String);
}

List_String gleam_string_to_graphemes_loop(String string, List_String acc) {
  Result_Tuple2_String_String_Nil S0;
  S0 = pop_grapheme_string(string);
  if (S0.tag == E_Ok) {
    String grapheme;
    grapheme = S0.val.Ok->value.field0;
    String rest;
    rest = S0.val.Ok->value.field1;
    List_String T0;
    T0 = new_Cons_String(grapheme, acc);
    return gleam_string_to_graphemes_loop(rest, T0);
  } else {
    if (S0.tag == E_Error) {
      return acc;
    } else {
      panic_exit(new_String("No matching clause in gleam/string.to_graphemes_loop", 52));
    }
  }
}

List_String gleam_string_to_graphemes(String string) {
  List_String T0;
  T0 = gleam_string_to_graphemes_loop(string, new_Empty_String);
  return gleam_list_reverse_String(T0);
}

glimage_bindings_Image glimage_bindings_update_img_data(glimage_bindings_Image img, String data) {
  return new_glimage_bindings_Image(img.w, img.h, data, img.channels);
}

Nil gleam_io_println(String string) {
  gleam_io_do_print(string);
  return gleam_io_do_print(new_String("\n", 1));
}

Nil glimage_main() {
  glimage_bindings_Image my_gleam_img;
  my_gleam_img = glimage_stbi_load(new_String("gleam.png", 9));
  glimage_bindings_print_image_info(my_gleam_img);
  String new_data;
  List_String T0;
  List_String T1;
  T1 = gleam_string_to_graphemes(my_gleam_img.data);
  T0 = gleam_list_reverse_String(T1);
  new_data = gleam_string_concat(T0);
  glimage_bindings_Image new_image;
  new_image = glimage_bindings_update_img_data(my_gleam_img, new_data);
  Result_Bool_String saved;
  saved = glimage_stbi_write_png(new_image, new_String("gleam_new.png", 13));
  Result_Bool_String S0;
  S0 = saved;
  if (S0.tag == E_Ok) {
    return gleam_io_println(new_String("Image succesfully saved", 23));
  } else {
    if (S0.tag == E_Error) {
      String e;
      e = S0.val.Error->value;
      String T2;
      T2 = append_string(new_String("There was an error saving the image: ", 37), e);
      return gleam_io_println(T2);
    } else {
      panic_exit(new_String("No matching clause in glimage.main", 34));
    }
  }
}


int main(int argc, char **argv) {
  init(argc, argv);
  glimage_main();
  return 0;
}
