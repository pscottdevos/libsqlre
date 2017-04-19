/*
 * Writen by P. Scott DeVos
 */

#include <pcre.h>
#include <sqlite3ext.h>
#include <string.h>
SQLITE_EXTENSION_INIT1

static void regexp(sqlite3_context *context, int argc, sqlite3_value **argv)
{
  const char *err, *re, *value;
  int len, pos, result;
  pcre *cre;
  pcre_extra  *extra;

	re = (const char *) sqlite3_value_text(argv[0]);
  if (!re) {
    sqlite3_result_error(context, "no regexp", -1);
    return;
  }

	value = (const char *) sqlite3_value_text(argv[1]);
  if (!value) {
    sqlite3_result_error(context, "no comparison value", -1);
    return;
  }

  cre = pcre_compile(re, 0, &err, &pos, NULL);
  if (!cre) {
    char *err_str = sqlite3_mprintf("%s: %s (offset %d)", re, err, pos);
    sqlite3_result_error(context, err_str, -1);
    sqlite3_free(err_str);
    return;
  }

  extra = pcre_study(cre, 0, &err);

  len = strlen(value);
  result = pcre_exec(cre, extra, value, len, 0, 0, NULL, 0);
  sqlite3_result_int(context, result >= 0);
  return;
}

int sqlite3_sqlre_init(
  sqlite3 *db, char **pzErrMsg, const sqlite3_api_routines *pApi
) {
  SQLITE_EXTENSION_INIT2(pApi)
  sqlite3_create_function(
    db, "REGEXP", 2, SQLITE_UTF8, NULL, regexp, NULL, NULL
  );
  return 0;
}
