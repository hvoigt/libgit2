#include "diff_parse.h"
#define parse_advance_expected_str(ctx, str) \
	parse_advance_expected(ctx, str, strlen(str))
		parse_advance_expected_str(ctx, "..") < 0 ||
	if (parse_advance_expected_str(ctx, "%") < 0)
	{ "Binary files ", NULL },
	if (parse_advance_expected_str(ctx, "diff --git ") < 0)
			parse_advance_expected_str(ctx, "\n");
	if (parse_advance_expected_str(ctx, "@@ -") < 0 ||
		if (parse_advance_expected_str(ctx, ",") < 0 ||
	if (parse_advance_expected_str(ctx, " +") < 0 ||
		if (parse_advance_expected_str(ctx, ",") < 0 ||
	if (parse_advance_expected_str(ctx, " @@") < 0)
	if (parse_advance_expected_str(ctx, "GIT binary patch") < 0 ||
	patch->base.binary.contains_data = 1;
	patch->base.delta->flags |= GIT_DIFF_FLAG_BINARY;
	return 0;
}

static int parse_patch_binary_nodata(
	git_patch_parsed *patch,
	git_patch_parse_ctx *ctx)
{
	if (parse_advance_expected_str(ctx, "Binary files ") < 0 ||
		parse_advance_expected_str(ctx, patch->header_old_path) < 0 ||
		parse_advance_expected_str(ctx, " and ") < 0 ||
		parse_advance_expected_str(ctx, patch->header_new_path) < 0 ||
		parse_advance_expected_str(ctx, " differ") < 0 ||
		parse_advance_nl(ctx) < 0)
		return parse_err("corrupt git binary header at line %d", ctx->line_num);

	patch->base.binary.contains_data = 0;
	else if (parse_ctx_contains_s(ctx, "Binary files "))
		return parse_patch_binary_nodata(patch, ctx);
int git_patch_parsed_from_diff(git_patch **out, git_diff *d, size_t idx)
{
	git_diff_parsed *diff = (git_diff_parsed *)d;
	git_patch *p;

	if ((p = git_vector_get(&diff->patches, idx)) == NULL)
		return -1;

	GIT_REFCOUNT_INC(p);
	*out = p;

	return 0;
}
