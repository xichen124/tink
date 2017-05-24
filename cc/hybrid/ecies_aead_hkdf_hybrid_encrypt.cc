// Copyright 2017 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
///////////////////////////////////////////////////////////////////////////////

#include "cc/hybrid/ecies_aead_hkdf_hybrid_encrypt.h"

#include "cc/hybrid_encrypt.h"
#include "cc/util/statusor.h"
#include "google/protobuf/stubs/stringpiece.h"
#include "proto/ecies_aead_hkdf.pb.h"
#include "proto/tink.pb.h"

using google::crypto::tink::EciesAeadHkdfPublicKey;
using util::Status;
using util::StatusOr;

namespace crypto {
namespace tink {

// static
util::StatusOr<std::unique_ptr<HybridEncrypt>>
EciesAeadHkdfHybridEncrypt::New(const EciesAeadHkdfPublicKey& recipient_key) {
  std::unique_ptr<HybridEncrypt> hybrid_encrypt(
      new EciesAeadHkdfHybridEncrypt(recipient_key));
  return std::move(hybrid_encrypt);
}

util::StatusOr<std::string> EciesAeadHkdfHybridEncrypt::Encrypt(
    google::protobuf::StringPiece plaintext,
    google::protobuf::StringPiece context_info) const {
  return Status(util::error::UNIMPLEMENTED, "not implemented yet");
}

}  // namespace tink
}  // namespace crypto
