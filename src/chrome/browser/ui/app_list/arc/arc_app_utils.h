// Copyright 2016 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef CHROME_BROWSER_UI_APP_LIST_ARC_ARC_APP_UTILS_H_
#define CHROME_BROWSER_UI_APP_LIST_ARC_ARC_APP_UTILS_H_

#include <string>

#include "base/callback.h"
#include "components/arc/common/app.mojom.h"
#include "ui/gfx/geometry/rect.h"

namespace content {
class BrowserContext;
}

namespace arc {

extern const char kPlayStoreAppId[];
extern const char kSettingsAppId[];

using CanHandleResolutionCallback = base::Callback<void(bool)>;

// Checks if a given app should be hidden in launcher.
bool ShouldShowInLauncher(const std::string& app_id);

// Launch an app and let the system decides how big and where to place it.
bool LaunchApp(content::BrowserContext* context, const std::string& app_id);

// Launch Android Settings app.
bool LaunchAndroidSettingsApp(content::BrowserContext* context);

// Launch an app with given layout and let the system decides how big and where
// to place it.
bool LaunchApp(content::BrowserContext* context,
               const std::string& app_id,
               bool landscape_layout);

// Launch an app and place it at the specified coordinates.
bool LaunchAppWithRect(content::BrowserContext* context,
                       const std::string& app_id,
                       const gfx::Rect& target_rect);

// Tests if the application can use the given target resolution.
// The callback will receive the information once known.
// A false will get returned if the result cannot be determined in which case
// the callback will not be called.
bool CanHandleResolution(content::BrowserContext* context,
    const std::string& app_id,
    const gfx::Rect& rect,
    const CanHandleResolutionCallback& callback);

// Uninstalls the package in ARC.
void UninstallPackage(const std::string& package_name);

// Removes cached app shortcut icon in ARC.
void RemoveCachedIcon(const std::string& icon_resource_id);

// Show package info for ARC package.
// Deprecated. Use ShowPackageInfoOnPage.
bool ShowPackageInfo(const std::string& package_name);

// Show package info for ARC package at the specified page.
bool ShowPackageInfoOnPage(const std::string& package_name,
                           mojom::ShowPackageInfoPage page);

}  // namespace arc

#endif  // CHROME_BROWSER_UI_APP_LIST_ARC_ARC_APP_UTILS_H_