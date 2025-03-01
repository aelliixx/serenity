/*
 * Copyright (c) 2018-2020, the SerenityOS developers.
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#pragma once

#include <AK/ByteBuffer.h>
#include <AK/ByteString.h>
#include <AK/HashMap.h>
#include <AK/OwnPtr.h>
#include <AK/URL.h>
#include <LibHTTP/HttpsJob.h>
#include <RequestServer/ConnectionFromClient.h>
#include <RequestServer/HttpsRequest.h>
#include <RequestServer/Protocol.h>
#include <RequestServer/Request.h>

namespace RequestServer {

class HttpsProtocol final : public Protocol {
public:
    using JobType = HTTP::HttpsJob;
    using RequestType = HttpsRequest;

    HttpsProtocol();
    ~HttpsProtocol() override = default;

    virtual OwnPtr<Request> start_request(i32, ConnectionFromClient&, ByteString const& method, const URL&, HashMap<ByteString, ByteString> const& headers, ReadonlyBytes body, Core::ProxyData proxy_data = {}) override;
};

}
