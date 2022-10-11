## BionetBF: A Novel Bloom Filter for Faster Membership Identification of Large Biological Graph

## Generate Dataset

To generate dataset, first compile

* ```$gcc data-gen-id_Kmer.c```

and then run the code

* ```$./a.out```

To compile the main code

* ```$gcc BionetBF.c```

To run the code

* ```$./a.out```


Citation: 

* Nayak, Sabuzima and Patgiri, Ripon, Bionetbf: A Novel Bloom Filter for Faster Membership Identification of Large Biological Graph. Available at SSRN: https://ssrn.com/abstract=4170144 or http://dx.doi.org/10.2139/ssrn.4170144 
* ```bibtex
@misc{nayak_bionetbf:_2022,

	address = {Rochester, NY},  
	type = {{SSRN} {Scholarly} {Paper}},  
	title = {Bionetbf: {A} {Novel} {Bloom} {Filter} for {Faster} {Membership} {Identification} of {Large} {Biological} {Graph}},  
	shorttitle = {Bionetbf},
	url = {https://papers.ssrn.com/abstract=4170144},
	doi = {10.2139/ssrn.4170144},
	abstract = {Algorithm This article proposes a novel Bloom Filter to determine the existence of a relationship in Big Graph, specifically biological networks. In this article, we propose a novel Bloom Filter called Biological network Bloom Filter (BionetBF) for fast membership identification of the biological network edges or paired biological data. BionetBF is capable of executing millions of operations within a second while occupying a tiny main memory footprint. We have conducted rigorous experiments to prove the performance of BionetBF with large datasets. The experiment is performed using 12 synthetic datasets and three biological network datasets. It takes less than 8 sec for insertion and query of 40 million biological edges. It demonstrates higher performance while maintaining a 0.001 false positive probability. BionetBF is compared with other filters: Cuckoo Filter and Libbloom, where small-sized BionetBF proves its supremacy by exhibiting higher performance compared with large-sized Cuckoo Filter and Libbloom. The source code is available at  https://github.com/patgiri/BionetB  F  . The code is written in the C programming language. All data are available at the given link.},
	language = {en},
	urldate = {2022-10-11},
	author = {Nayak, Sabuzima and Patgiri, Ripon},
	month = jul,
	year = {2022},
	keywords = {Keywords: Bloom Filter, Big Graph, Biological Network, Probabilistic Data Structure, algorithm},
}
```

Contributed by

* Ms. Sabuzima Nayak

* Dr. Ripon Patgiri, URL: http://cs.nits.ac.in/rp
