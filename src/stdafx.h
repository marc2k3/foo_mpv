#pragma once
#define _ATL_MODULES
#define _WIN32_WINNT _WIN32_WINNT_WIN7
#define WINVER _WIN32_WINNT_WIN7
#define _DISABLE_CONSTEXPR_MUTEX_CONSTRUCTOR

#include <stddef.h>
#include <stdint.h>

#include <algorithm>
#include <atomic>
#include <condition_variable>
#include <functional>
#include <iomanip>
#include <list>
#include <map>
#include <mutex>
#include <queue>
#include <set>
#include <sstream>
#include <thread>

#include <nlohmann/json.hpp>

#include "foobar2000-sdk/foobar2000/helpers/foobar2000+atl.h"
#include <helpers/atl-misc.h>
#include <helpers/BumpableElem.h>
#include <helpers/VolumeMap.h>
#include <helpers/win32_misc.h>
#include <helpers/WindowPositionUtils.h>
