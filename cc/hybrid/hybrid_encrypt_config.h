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

#ifndef TINK_HYBRID_HYBRID_ENCRYPT_CONFIG_H_
#define TINK_HYBRID_HYBRID_ENCRYPT_CONFIG_H_

#include "cc/hybrid_encrypt.h"
#include "cc/key_manager.h"
#include "cc/util/status.h"

namespace crypto {
namespace tink {

///////////////////////////////////////////////////////////////////////////////
// HybridEncryptConfig offers convenience methods for initializing
// HybridEncryptFactory and the underlying Registry.INSTANCE.
// In particular, it  allows for initalizing the Registry with native
// key types and their managers that Tink supports out of the box.
// These key types are divided in two groups:
//
//  - standard: secure and safe to use in new code. Over time, with
//    new developments in cryptanalysis and computing power, some
//    standard key types might become legacy.
//
//  - legacy: deprecated and insecure or obsolete, should not be used
//    in new code. Existing users should upgrade to one of the standard
//    key types.
//
// This divison allows for gradual retiring insecure or obsolete key types.
//
// For more information on how to obtain and use HybridEncrypt primitives
// see HybridEncryptFactory.
class HybridEncryptConfig {
 public:
  // Registers standard HybridEncrypt key types and their managers.
  static crypto::tink::util::Status RegisterStandardKeyTypes();

  // Registers legacy HybridEncrypt key types and their managers.
  static crypto::tink::util::Status RegisterLegacyKeyTypes();

  // Registers the given 'key_manager' for the key type
  // key_manager->get_key_type().
  // Takes ownership of 'key_manager', which must be non-nullptr.
  static crypto::tink::util::Status RegisterKeyManager(
      KeyManager<HybridEncrypt>* key_manager);

 private:
  HybridEncryptConfig() {}
};

}  // namespace tink
}  // namespace crypto

#endif  // TINK_HYBRID_HYBRID_ENCRYPT_CONFIG_H_
