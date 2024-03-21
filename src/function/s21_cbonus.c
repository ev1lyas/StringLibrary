#include "../s21_string.h"

// bonus C# No 1 Rayf
void *s21_to_upper(const char *str) {
  if (str == S21_NULL) return S21_NULL;

  int len = s21_strlen(str);
  char *c_str = (char *)malloc((len + 1) * sizeof(char));

  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      c_str[i] = str[i] - 32;
    } else {
      c_str[i] = str[i];
    }
  }
  c_str[len] = '\0';

  return (c_str);
}

// bonus C# No 2 Rayf
void *s21_to_lower(const char *str) {
  if (str == S21_NULL) return S21_NULL;

  int len = s21_strlen(str);
  char *c_str = (char *)malloc((len + 1) * sizeof(char));

  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      c_str[i] = str[i] + 32;
    } else {
      c_str[i] = str[i];
    }
  }
  c_str[len] = '\0';

  return (c_str);
}

// bonus C# No 3 Rayf
void *s21_insert(const char *src, const char *str, s21_size_t start_index) {
  void *res = S21_NULL;

  if (str != S21_NULL && src != S21_NULL) {
    s21_size_t src_len = s21_strlen(src);
    s21_size_t str_len = s21_strlen(str);

    if (start_index <= src_len) {
      char *new_str = malloc((src_len + str_len + 1) * sizeof(char));
      if (new_str != S21_NULL) {
        s21_strncpy(new_str, src, start_index);
        s21_strncpy(new_str + start_index, str, str_len);
        s21_strcpy(new_str + start_index + str_len, src + start_index);
        res = new_str;
      }
    }
  }
  return res;
}

// bonus C# No 4 Rayf
void *s21_trim(const char *src, const char *trim_chars) {
  char *res = S21_NULL;

  if (src != S21_NULL) {
    if (trim_chars != S21_NULL && *trim_chars) {
      const char *start = src;
      const char *end = src + s21_strlen(src);

      while (*start && s21_strchr(trim_chars, *start)) {
        start++;
      }

      while (end != start && s21_strchr(trim_chars, *(end - 1))) {
        end--;
      }

      res = malloc((end - start + 1) * sizeof(char));

      if (res) {
        s21_strncpy(res, start, end - start);
        res[end - start] = '\0';
      }
    } else {
      res = s21_trim(src, " \t\n");
    }
  }
  return res;
}