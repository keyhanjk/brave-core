/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this file,
 * You can obtain one at http://mozilla.org/MPL/2.0/. */

export const getMockChrome = () => {
  return {
    send: () => undefined,
    getVariableValue: () => undefined
  }
}

export const welcomeInitialState = {
  welcomeData: {
    pageIndex: 0
  }
}

export const rewardsInitialState = {
  rewardsData: {
    walletCreated: false,
    walletCreateFailed: false
  }
}

export const adblockInitialState = {
  adblockData: {
    stats: {
      numBlocked: 0,
      regionalAdBlockEnabled: false
    }
  }
}
