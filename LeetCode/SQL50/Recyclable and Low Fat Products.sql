-- Membuat tabel Products dengan ENUM untuk low_fats dan recyclable
CREATE TYPE fat_status AS ENUM ('Y', 'N');
CREATE TYPE recycle_status AS ENUM ('Y', 'N');

CREATE TABLE Products (
    product_id SERIAL PRIMARY KEY,
    low_fats fat_status NOT NULL,
    recyclable recycle_status NOT NULL
);

-- Memasukkan data sesuai contoh
INSERT INTO Products (product_id, low_fats, recyclable) VALUES
(0, 'Y', 'N'),
(1, 'Y', 'Y'),
(2, 'N', 'Y'),
(3, 'Y', 'Y'),
(4, 'N', 'N');

-- Query untuk mencari produk yang low fat dan recyclable
SELECT product_id 
FROM Products 
WHERE low_fats = 'Y' AND recyclable = 'Y';


-- solution
SELECT product_id FROM Products
WHERE low_fats = 'Y' AND recyclable = 'Y'