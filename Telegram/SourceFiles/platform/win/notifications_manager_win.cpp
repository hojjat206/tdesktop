/*
This file is part of Telegram Desktop,
the official desktop version of Telegram messaging app, see https://telegram.org

Telegram Desktop is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

It is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

In addition, as a special exception, the copyright holders give permission
to link the code of portions of this program with the OpenSSL library.

Full license: https://github.com/telegramdesktop/tdesktop/blob/master/LICENSE
Copyright (c) 2014-2016 John Preston, https://desktop.telegram.org
*/
#include "stdafx.h"
#include "platform/win/notifications_manager_win.h"

#include "platform/win/windows_toasts.h"

namespace Platform {
namespace Notifications {
namespace {

NeverFreedPointer<Toasts::Manager> ToastsManager;

} // namespace

void start() {
	Toasts::start();
}

Window::Notifications::AbstractManager *manager() {
	if (Toasts::supported()) {
		ToastsManager.makeIfNull();
		return ToastsManager.data();
	}
	return nullptr;
}

void finish() {
	ToastsManager.reset();
}

} // namespace Notifications
} // namespace Platform