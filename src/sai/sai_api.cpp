#include <squirrel.h>
#include <sqstdmath.h>
#include <sqstdstring.h>
#include <sqstdsystem.h>
#include "../stdafx.h"
#include "../debug.h"
#include "../script/squirrel.hpp"
#include "../script/squirrel_class.hpp"
#include "../script/squirrel_helper.hpp"
#include "../script/squirrel_helper_type.hpp"

#include "sai.hpp"

#define DEFINE_SCRIPT_FILES

#undef DEFINE_SCRIPT_FILES

void Register_SAI_API(Squirrel* engine)
{
	// basic squirrel library support
	sqstd_register_mathlib(engine->GetVM());
	sqstd_register_stringlib(engine->GetVM());
	sqstd_register_systemlib(engine->GetVM());
}