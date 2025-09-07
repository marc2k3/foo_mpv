#include "stdafx.h"
// PCH ^

#define VERSION_NO "0.0.0 alpha 0"

#include "acfu-sdk/acfu_github.h"
#include "acfu-sdk/utils/common.h"

const char* about =
    "Copyright (c) sammoth, 2020\n"
    "\n"
    "This component uses the following libraries:\n"
    "\n"
    "FFmpeg, licensed under the LGPL v2.1 "
    "(https://www.gnu.org/licenses/old-licenses/lgpl-2.1.html)\n"
    "Source available at: https://github.com/sammoth/foo_mpv/releases\n"
    "\n"
    "mpv, licensed under GPL v2.0 "
    "(https://www.gnu.org/licenses/old-licenses/gpl-2.0.en.html)\n"
    "Source available at: https://github.com/sammoth/foo_mpv/releases\n"
    "\n"
    "libvpx:\n"
    "\tCopyright (c) 2010, The WebM Project authors. All rights reserved.\n"
    "\tRedistribution and use in source and binary forms, with or without\n"
    "\tmodification, are permitted provided that the following conditions are\n"
    "\tmet:\n"
    "\t  * Redistributions of source code must retain the above copyright\n"
    "\t\tnotice, this list of conditions and the following disclaimer.\n"
    "\t  * Redistributions in binary form must reproduce the above copyright\n"
    "\t\tnotice, this list of conditions and the following disclaimer in\n"
    "\t\tthe documentation and/or other materials provided with the\n"
    "\t\tdistribution.\n"
    "\t  * Neither the name of Google, nor the WebM Project, nor the names\n"
    "\t\tof its contributors may be used to endorse or promote products\n"
    "\t\tderived from this software without specific prior written\n"
    "\t\tpermission.\n"
    "\tTHIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS\n"
    "\t\"AS IS\" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT\n"
    "\tLIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR\n"
    "\tA PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT\n"
    "\tHOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,\n"
    "\tSPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT\n"
    "\tLIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,\n"
    "\tDATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY\n"
    "\tTHEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT\n"
    "\t(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE\n"
    "\tOF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.\n"
    "\n"
    "\n"
    "SQLiteCpp, licensed under MIT:\n"
    "\tThe MIT License (MIT)\n"
    "\n"
    "\tCopyright (c) 2012-2020 Sebastien Rombauts "
    "(sebastien.rombauts@gmail.com)\n"
    "\n"
    "\tPermission is hereby granted, free of charge, to any person obtaining a "
    "copy\n"
    "\tof this software and associated documentation files (the \"Software\"), "
    "to deal\n"
    "\tin the Software without restriction, including without limitation the "
    "rights\n"
    "\tto use, copy, modify, merge, publish, distribute, sublicense, and/or "
    "sell\n"
    "\tcopies of the Software, and to permit persons to whom the Software is "
    "furnished\n"
    "\tto do so, subject to the following conditions:\n"
    "\n"
    "\tThe above copyright notice and this permission notice shall be included "
    "in all\n"
    "\tcopies or substantial portions of the Software.\n"
    "\n"
    "\tTHE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, "
    "EXPRESS OR\n"
    "\tIMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF "
    "MERCHANTABILITY,\n"
    "\tFITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL "
    "THE\n"
    "\tAUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER "
    "LIABILITY,\n"
    "\tWHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT "
    "OF OR\n"
    "\tIN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE "
    "SOFTWARE.\n"
    "\n"
    "zlib compression library:\n"
    "\t(C) 1995-2017 Jean-loup Gailly and Mark Adler\n"
    "Icons from the GNOME Project http://www.gnome.org\n"
    "\n"
    "\tThis work is licenced under the Creative Commons Attribution-Share "
    "Alike 3.0 United States License. To view a copy of this licence, visit "
    "http://creativecommons.org/licenses/by-sa/3.0/ or send a letter to "
    "Creative Commons, 171 Second Street, Suite 300, San Francisco, California "
    "94105, USA.\n"
    "\n";

DECLARE_COMPONENT_VERSION("mpv Video", VERSION_NO, about);
VALIDATE_COMPONENT_FILENAME("foo_mpv.dll");

namespace {
class FooMpvSource : public acfu::source, public qwr::acfu::github_conf {
 public:
  const char* my_version() const { return VERSION_NO; }
  virtual GUID get_guid() {
    static const GUID guid = {0x63f5b5d7,
                              0x3747,
                              0x449f,
                              {0xaa, 0xad, 0x9f, 0xa5, 0x38, 0x5, 0x22, 0xce}};

    return guid;
  }
  virtual void get_info(file_info& info) {
    info.meta_set("version", my_version());
    info.meta_set("name", "mpv Video");
    info.meta_set("module", "foo_mpv");
  }
  virtual bool is_newer(const file_info& info) {
    const char* version = info.meta_get("version", 0);
    return acfu::is_newer(version, my_version());
  }
  virtual acfu::request::ptr create_request() {
    return new service_impl_t<qwr::acfu::github_latest_release<FooMpvSource>>();
  }
  static pfc::string8 get_owner() { return "sammoth"; }
  static pfc::string8 get_repo() { return "foo_mpv"; }
};
static service_factory_t<FooMpvSource> g_mpv_source;
}  // namespace
