/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "brave/components/brave_shields/browser/brave_shields_resource_throttle.h"
#include "net/url_request/url_request.h"
#include "chrome/browser/browser_process.h"
#include "brave/components/brave_shields/browser/ad_block_service.h"
#include "brave/components/brave_shields/browser/tracking_protection_service.h"

content::ResourceThrottle* MaybeCreateBraveShieldsResourceThrottle(
    net::URLRequest* request,
    content::ResourceType resource_type) {
  return new BraveShieldsResourceThrottle(request, resource_type);
}

BraveShieldsResourceThrottle::BraveShieldsResourceThrottle(
    const net::URLRequest* request,
    content::ResourceType resource_type) {
  resource_type_ = resource_type;
  request_ = request;
}

BraveShieldsResourceThrottle::~BraveShieldsResourceThrottle() = default;

const char* BraveShieldsResourceThrottle::GetNameForLogging() const {
  return "BraveShieldsResourceThrottle";
}

void BraveShieldsResourceThrottle::WillStartRequest(bool* defer) {
  if (!g_browser_process->tracking_protection_service()->
      ShouldStartRequest(request_->url(),
      resource_type_,
      request_->initiator()->host())) {
    Cancel();
  }
  if (!g_browser_process->ad_block_service()->
      ShouldStartRequest(request_->url(),
      resource_type_,
      request_->initiator()->host())) {
    Cancel();
  }
}