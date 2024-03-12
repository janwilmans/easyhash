
namespace details {

// Disclaimer:
// The FNV-1a algorithm is not cryptographically safe and should relied on for any kind of security
// That being said, it is claimed to have a pretty good uniqueness / distribution.

constexpr uint32_t FNV_OFFSET_BASIS = 0x811c9dc5;
constexpr uint32_t FNV_PRIME = 0x01000193;
constexpr uint32_t RND_ADDITION = 0xAF05FF00;

// there each byte is converted to a 32-bit unsigned number first,
// I am not sure if that will mess with the hash distribution, RND_ADDITION was added
// to at least not have all data prefixed with zeros.
[[nodiscard]] constexpr uint32_t fnv1a_hash(std::string_view value) noexcept
{
    uint32_t hash = FNV_OFFSET_BASIS;
    for (size_t i = 0; i < value.size(); ++i)
    {
        hash ^= (static_cast<uint32_t>(value[i]) | RND_ADDITION);
        hash *= FNV_PRIME;
    }
    return hash;
}

struct unsafe_hash32_t
{
    std::uint32_t value;

    [[nodiscard]] constexpr bool operator==(std::uint32_t other) const noexcept
    {
        return value == other;
    }
    [[nodiscard]] constexpr bool operator==(unsafe_hash32_t other) const noexcept
    {
        return value == other.value;
    }
};

[[nodiscard]] std::uint32_t format_as(const unsafe_hash32_t & hash)
{
    return hash.value;
}

} // namespace details

// notice the consteval guarantees this string literal does _NOT_ end up in the binary.
consteval details::unsafe_hash32_t operator"" _unsafe_hash(const char * str, size_t size)
{
    return details::unsafe_hash32_t(details::fnv1a_hash({str, size}));
}