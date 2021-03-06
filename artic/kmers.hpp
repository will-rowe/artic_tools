#ifndef KMERS_H
#define KMERS_H

#include <unordered_set>
#include <vector>

namespace artic
{
    // kmer_t represents an encoded k-mer.
    typedef uint64_t kmer_t;

    // kmerset is a container for kmers.
    typedef std::vector<kmer_t> kmerset_t;

    // MAX_K_SIZE is the maximum k-mer size permitted (based on 2-bit encoding of bases)
    const uint32_t MAX_K_SIZE = sizeof(kmer_t) * 4;

    // nt2char is a lookup to convert nucleotides to integers.
    const uint8_t nt2char[256] =
        {
            4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
            4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
            4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
            4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
            4, 0, 4, 1, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4, 4, 4,
            4, 4, 4, 4, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
            4, 0, 4, 1, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4, 4, 4,
            4, 4, 4, 4, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
            4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
            4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
            4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
            4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
            4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
            4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
            4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
            4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4};

    // char2nt is a lookup to convert integers to nucleotides.
    const uint8_t char2nt[5] = {'A', 'C', 'G', 'T', 'N'};

    // GetEncodedKmers will compute and integer encode all canonical k-mers in a sequence, adding them to the provided container.
    void GetEncodedKmers(const char* seq, uint32_t seqLen, uint32_t kSize, kmerset_t& kmers);

    // GetRCencoding will reverse complement an encoded k-mer.
    kmer_t GetRCencoding(kmer_t encodedKmer, uint32_t kSize);

    // DecodeKmer will decode an integer encoded k-mer.
    void DecodeKmer(kmer_t encodedKmer, uint32_t kSize, std::string& decodedKmer);

    // DecodeKmer_rc will decode an integer encoded k-mer to it's reverse complement.
    void DecodeKmer_rc(kmer_t encodedKmer, uint32_t kSize, std::string& decodedKmer);

} // namespace artic

#endif