CREATE TABLE [dbo].[UsersTable] (
  [id] INT PRIMARY KEY IDENTITY(1, 1) NOT NULL,
  [first_name] VARCHAR(20) NOT NULL,
  [last_name] VARCHAR(20) NOT NULL,
  [email] VARCHAR(70) UNIQUE NOT NULL,
  [password] VARCHAR(128),
  [dob] DATE,
  [gender] VARCHAR(10),
  [contact] VARCHAR(15),
  [role] VARCHAR(10) NOT NULL DEFAULT 'USER',
  [created_at] TIMESTAMP NOT NULL
)
GO

CREATE TABLE [dbo].[SuppliersTable] (
  [id] INT IDENTITY(1,1) PRIMARY KEY NOT NULL,
  [name] VARCHAR(70) NOT NULL,
  [address] VARCHAR(100) NOT NULL,
  [email] VARCHAR(70) UNIQUE NOT NULL,
  [contact] VARCHAR(15) NOT NULL,
  [created_at] TIMESTAMP NOT NULL
)
GO

CREATE TABLE [dbo].[BooksTable] (
  [isbn] INT PRIMARY KEY NOT NULL,
  [title] VARCHAR(100) NOT NULL,
  [author] VARCHAR(70) NOT NULL,
  [genre] VARCHAR(50) NOT NULL,
  [publisher] VARCHAR(70) NOT NULL,
  [unit_price] FLOAT NOT NULL,
  [stock_qty] INT DEFAULT (0),
  [supplier] INT NOT NULL,
  [created_at] TIMESTAMP NOT NULL,
  CONSTRAINT [FK_Book2Supplier] FOREIGN KEY ([supplier]) REFERENCES [dbo].[SuppliersTable] ([id])
)
GO

CREATE TABLE [dbo].[OrdersTable] (
  [id] INT IDENTITY(1,1) PRIMARY KEY NOT NULL,
  [user] INT NOT NULL,
  [supplier] INT NOT NULL,
  [book] INT NOT NULL,
  [qty] INT DEFAULT 0,
  [status] INT DEFAULT 0,
  [created_at] TIMESTAMP NOT NULL,
  CONSTRAINT [FK_Order2User] FOREIGN KEY ([user]) REFERENCES [dbo].[UsersTable] ([id]),
  CONSTRAINT [FK_Order2Supplier] FOREIGN KEY ([supplier]) REFERENCES [dbo].[SuppliersTable] ([id]),
  CONSTRAINT [FK_Order2Book] FOREIGN KEY ([book]) REFERENCES [dbo].[BooksTable] ([isbn])
)
GO
