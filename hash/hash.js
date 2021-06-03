class Hash {

  constructor(size) {
    this.data = new Array(size);
  }

  _hash(key) {
    let hash = 0;
    for (let i=0;i < key.length; i++) {
      hash = (hash + key.charCodeAt(i) * i) % this.data.length;
    }

    return hash;
  }

  set(key, value) {
    const address = this._hash(key);
    if (!this.data[address]) {
      this.data[address] = []
    }
    this.data[address].push([key, value]);
  }

  get (key) {
    const address = this._hash(key);
    const currentBucket = this.data[address];
    if (currentBucket) {
      for (let i =0; i< currentBucket.length; i++) {
        if (currentBucket[i][0] === key) {
          return currentBucket[i]
        }
      }
    }
    return undefined;
  }

  keys() {
    if (!this.data.length) {
      return undefined
    }

    let results = [];

    for (let i =0; i < this.data.length; i++) {
      if (this.data[i] && this.data[i].length) {
        if (this.data[i].length > 1){
          for (let j =0 ; j < this.data[i].length ;j++) {
            results.push(this.data[i][j][0]);
          }
        } else{
          results.push(this.data[i][0][0]);
        }

      }
    }

    return results;
  }
}

const newHashTable = new Hash(2);

newHashTable.set('grapes', 1000);
newHashTable.set('grapess', 11000);
newHashTable.set('gorange', 12000);
newHashTable.set('missing', 18000);

newHashTable.data
newHashTable.keys();