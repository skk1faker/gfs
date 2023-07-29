// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: gfs_server.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_gfs_5fserver_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_gfs_5fserver_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3019000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3019004 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_bases.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_gfs_5fserver_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_gfs_5fserver_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[2]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_gfs_5fserver_2eproto;
namespace ChunkServer {
class HeartBeat;
struct HeartBeatDefaultTypeInternal;
extern HeartBeatDefaultTypeInternal _HeartBeat_default_instance_;
class VoidMessage;
struct VoidMessageDefaultTypeInternal;
extern VoidMessageDefaultTypeInternal _VoidMessage_default_instance_;
}  // namespace ChunkServer
PROTOBUF_NAMESPACE_OPEN
template<> ::ChunkServer::HeartBeat* Arena::CreateMaybeMessage<::ChunkServer::HeartBeat>(Arena*);
template<> ::ChunkServer::VoidMessage* Arena::CreateMaybeMessage<::ChunkServer::VoidMessage>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace ChunkServer {

// ===================================================================

class VoidMessage final :
    public ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase /* @@protoc_insertion_point(class_definition:ChunkServer.VoidMessage) */ {
 public:
  inline VoidMessage() : VoidMessage(nullptr) {}
  explicit constexpr VoidMessage(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  VoidMessage(const VoidMessage& from);
  VoidMessage(VoidMessage&& from) noexcept
    : VoidMessage() {
    *this = ::std::move(from);
  }

  inline VoidMessage& operator=(const VoidMessage& from) {
    CopyFrom(from);
    return *this;
  }
  inline VoidMessage& operator=(VoidMessage&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const VoidMessage& default_instance() {
    return *internal_default_instance();
  }
  static inline const VoidMessage* internal_default_instance() {
    return reinterpret_cast<const VoidMessage*>(
               &_VoidMessage_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(VoidMessage& a, VoidMessage& b) {
    a.Swap(&b);
  }
  inline void Swap(VoidMessage* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(VoidMessage* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  VoidMessage* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<VoidMessage>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase::CopyFrom;
  inline void CopyFrom(const VoidMessage& from) {
    ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase::CopyImpl(this, from);
  }
  using ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase::MergeFrom;
  void MergeFrom(const VoidMessage& from) {
    ::PROTOBUF_NAMESPACE_ID::internal::ZeroFieldsBase::MergeImpl(this, from);
  }
  public:

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "ChunkServer.VoidMessage";
  }
  protected:
  explicit VoidMessage(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // @@protoc_insertion_point(class_scope:ChunkServer.VoidMessage)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_gfs_5fserver_2eproto;
};
// -------------------------------------------------------------------

class HeartBeat final :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:ChunkServer.HeartBeat) */ {
 public:
  inline HeartBeat() : HeartBeat(nullptr) {}
  ~HeartBeat() override;
  explicit constexpr HeartBeat(::PROTOBUF_NAMESPACE_ID::internal::ConstantInitialized);

  HeartBeat(const HeartBeat& from);
  HeartBeat(HeartBeat&& from) noexcept
    : HeartBeat() {
    *this = ::std::move(from);
  }

  inline HeartBeat& operator=(const HeartBeat& from) {
    CopyFrom(from);
    return *this;
  }
  inline HeartBeat& operator=(HeartBeat&& from) noexcept {
    if (this == &from) return *this;
    if (GetOwningArena() == from.GetOwningArena()
  #ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetOwningArena() != nullptr
  #endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const HeartBeat& default_instance() {
    return *internal_default_instance();
  }
  static inline const HeartBeat* internal_default_instance() {
    return reinterpret_cast<const HeartBeat*>(
               &_HeartBeat_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(HeartBeat& a, HeartBeat& b) {
    a.Swap(&b);
  }
  inline void Swap(HeartBeat* other) {
    if (other == this) return;
  #ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() != nullptr &&
        GetOwningArena() == other->GetOwningArena()) {
   #else  // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetOwningArena() == other->GetOwningArena()) {
  #endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(HeartBeat* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetOwningArena() == other->GetOwningArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  HeartBeat* New(::PROTOBUF_NAMESPACE_ID::Arena* arena = nullptr) const final {
    return CreateMaybeMessage<HeartBeat>(arena);
  }
  using ::PROTOBUF_NAMESPACE_ID::Message::CopyFrom;
  void CopyFrom(const HeartBeat& from);
  using ::PROTOBUF_NAMESPACE_ID::Message::MergeFrom;
  void MergeFrom(const HeartBeat& from);
  private:
  static void MergeImpl(::PROTOBUF_NAMESPACE_ID::Message* to, const ::PROTOBUF_NAMESPACE_ID::Message& from);
  public:
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  uint8_t* _InternalSerialize(
      uint8_t* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(HeartBeat* other);

  private:
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "ChunkServer.HeartBeat";
  }
  protected:
  explicit HeartBeat(::PROTOBUF_NAMESPACE_ID::Arena* arena,
                       bool is_message_owned = false);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  static const ClassData _class_data_;
  const ::PROTOBUF_NAMESPACE_ID::Message::ClassData*GetClassData() const final;

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kChunkaddlistFieldNumber = 3,
    kChunkdellistFieldNumber = 4,
    kWorktimesFieldNumber = 1,
    kChunkaddcountFieldNumber = 2,
  };
  // repeated int64 chunkaddlist = 3;
  int chunkaddlist_size() const;
  private:
  int _internal_chunkaddlist_size() const;
  public:
  void clear_chunkaddlist();
  private:
  int64_t _internal_chunkaddlist(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >&
      _internal_chunkaddlist() const;
  void _internal_add_chunkaddlist(int64_t value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >*
      _internal_mutable_chunkaddlist();
  public:
  int64_t chunkaddlist(int index) const;
  void set_chunkaddlist(int index, int64_t value);
  void add_chunkaddlist(int64_t value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >&
      chunkaddlist() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >*
      mutable_chunkaddlist();

  // repeated int64 chunkdellist = 4;
  int chunkdellist_size() const;
  private:
  int _internal_chunkdellist_size() const;
  public:
  void clear_chunkdellist();
  private:
  int64_t _internal_chunkdellist(int index) const;
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >&
      _internal_chunkdellist() const;
  void _internal_add_chunkdellist(int64_t value);
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >*
      _internal_mutable_chunkdellist();
  public:
  int64_t chunkdellist(int index) const;
  void set_chunkdellist(int index, int64_t value);
  void add_chunkdellist(int64_t value);
  const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >&
      chunkdellist() const;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >*
      mutable_chunkdellist();

  // int32 worktimes = 1;
  void clear_worktimes();
  int32_t worktimes() const;
  void set_worktimes(int32_t value);
  private:
  int32_t _internal_worktimes() const;
  void _internal_set_worktimes(int32_t value);
  public:

  // int32 chunkaddcount = 2;
  void clear_chunkaddcount();
  int32_t chunkaddcount() const;
  void set_chunkaddcount(int32_t value);
  private:
  int32_t _internal_chunkaddcount() const;
  void _internal_set_chunkaddcount(int32_t value);
  public:

  // @@protoc_insertion_point(class_scope:ChunkServer.HeartBeat)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t > chunkaddlist_;
  mutable std::atomic<int> _chunkaddlist_cached_byte_size_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t > chunkdellist_;
  mutable std::atomic<int> _chunkdellist_cached_byte_size_;
  int32_t worktimes_;
  int32_t chunkaddcount_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  friend struct ::TableStruct_gfs_5fserver_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// VoidMessage

// -------------------------------------------------------------------

// HeartBeat

// int32 worktimes = 1;
inline void HeartBeat::clear_worktimes() {
  worktimes_ = 0;
}
inline int32_t HeartBeat::_internal_worktimes() const {
  return worktimes_;
}
inline int32_t HeartBeat::worktimes() const {
  // @@protoc_insertion_point(field_get:ChunkServer.HeartBeat.worktimes)
  return _internal_worktimes();
}
inline void HeartBeat::_internal_set_worktimes(int32_t value) {
  
  worktimes_ = value;
}
inline void HeartBeat::set_worktimes(int32_t value) {
  _internal_set_worktimes(value);
  // @@protoc_insertion_point(field_set:ChunkServer.HeartBeat.worktimes)
}

// int32 chunkaddcount = 2;
inline void HeartBeat::clear_chunkaddcount() {
  chunkaddcount_ = 0;
}
inline int32_t HeartBeat::_internal_chunkaddcount() const {
  return chunkaddcount_;
}
inline int32_t HeartBeat::chunkaddcount() const {
  // @@protoc_insertion_point(field_get:ChunkServer.HeartBeat.chunkaddcount)
  return _internal_chunkaddcount();
}
inline void HeartBeat::_internal_set_chunkaddcount(int32_t value) {
  
  chunkaddcount_ = value;
}
inline void HeartBeat::set_chunkaddcount(int32_t value) {
  _internal_set_chunkaddcount(value);
  // @@protoc_insertion_point(field_set:ChunkServer.HeartBeat.chunkaddcount)
}

// repeated int64 chunkaddlist = 3;
inline int HeartBeat::_internal_chunkaddlist_size() const {
  return chunkaddlist_.size();
}
inline int HeartBeat::chunkaddlist_size() const {
  return _internal_chunkaddlist_size();
}
inline void HeartBeat::clear_chunkaddlist() {
  chunkaddlist_.Clear();
}
inline int64_t HeartBeat::_internal_chunkaddlist(int index) const {
  return chunkaddlist_.Get(index);
}
inline int64_t HeartBeat::chunkaddlist(int index) const {
  // @@protoc_insertion_point(field_get:ChunkServer.HeartBeat.chunkaddlist)
  return _internal_chunkaddlist(index);
}
inline void HeartBeat::set_chunkaddlist(int index, int64_t value) {
  chunkaddlist_.Set(index, value);
  // @@protoc_insertion_point(field_set:ChunkServer.HeartBeat.chunkaddlist)
}
inline void HeartBeat::_internal_add_chunkaddlist(int64_t value) {
  chunkaddlist_.Add(value);
}
inline void HeartBeat::add_chunkaddlist(int64_t value) {
  _internal_add_chunkaddlist(value);
  // @@protoc_insertion_point(field_add:ChunkServer.HeartBeat.chunkaddlist)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >&
HeartBeat::_internal_chunkaddlist() const {
  return chunkaddlist_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >&
HeartBeat::chunkaddlist() const {
  // @@protoc_insertion_point(field_list:ChunkServer.HeartBeat.chunkaddlist)
  return _internal_chunkaddlist();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >*
HeartBeat::_internal_mutable_chunkaddlist() {
  return &chunkaddlist_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >*
HeartBeat::mutable_chunkaddlist() {
  // @@protoc_insertion_point(field_mutable_list:ChunkServer.HeartBeat.chunkaddlist)
  return _internal_mutable_chunkaddlist();
}

// repeated int64 chunkdellist = 4;
inline int HeartBeat::_internal_chunkdellist_size() const {
  return chunkdellist_.size();
}
inline int HeartBeat::chunkdellist_size() const {
  return _internal_chunkdellist_size();
}
inline void HeartBeat::clear_chunkdellist() {
  chunkdellist_.Clear();
}
inline int64_t HeartBeat::_internal_chunkdellist(int index) const {
  return chunkdellist_.Get(index);
}
inline int64_t HeartBeat::chunkdellist(int index) const {
  // @@protoc_insertion_point(field_get:ChunkServer.HeartBeat.chunkdellist)
  return _internal_chunkdellist(index);
}
inline void HeartBeat::set_chunkdellist(int index, int64_t value) {
  chunkdellist_.Set(index, value);
  // @@protoc_insertion_point(field_set:ChunkServer.HeartBeat.chunkdellist)
}
inline void HeartBeat::_internal_add_chunkdellist(int64_t value) {
  chunkdellist_.Add(value);
}
inline void HeartBeat::add_chunkdellist(int64_t value) {
  _internal_add_chunkdellist(value);
  // @@protoc_insertion_point(field_add:ChunkServer.HeartBeat.chunkdellist)
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >&
HeartBeat::_internal_chunkdellist() const {
  return chunkdellist_;
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >&
HeartBeat::chunkdellist() const {
  // @@protoc_insertion_point(field_list:ChunkServer.HeartBeat.chunkdellist)
  return _internal_chunkdellist();
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >*
HeartBeat::_internal_mutable_chunkdellist() {
  return &chunkdellist_;
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedField< int64_t >*
HeartBeat::mutable_chunkdellist() {
  // @@protoc_insertion_point(field_mutable_list:ChunkServer.HeartBeat.chunkdellist)
  return _internal_mutable_chunkdellist();
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace ChunkServer

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_gfs_5fserver_2eproto
